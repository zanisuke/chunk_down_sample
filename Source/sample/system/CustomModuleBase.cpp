// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomModuleBase.h"
#include "Engine.h"

//----------------------------------------------------------
// ctor
//----------------------------------------------------------
CustomModuleBase::CustomModuleBase()
{
	CustomModuleManager::GetInstance().AddModule(this);
}

//----------------------------------------------------------
// GetWorld
//----------------------------------------------------------
UWorld* CustomModuleBase::GetWorld() const
{
	return (mpOwnerInstance) ? mpOwnerInstance->GetWorld() : nullptr;
}

//----------------------------------------------------------
// AddModule
//----------------------------------------------------------
void CustomModuleManager::AddModule(CustomModuleBase* pModule)
{
	check(pModule);
	mpAppModules.Add(pModule);
}

//----------------------------------------------------------
// InitModules
//----------------------------------------------------------
void CustomModuleManager::InitModules(UGameInstance* pOwner)
{
	for (CustomModuleBase* Module : mpAppModules)
	{
		Module->SetOwnerInstance(pOwner);
	}

	mhTickPre = FWorldDelegates::OnWorldPreActorTick.AddRaw(this, &CustomModuleManager::TickPreModules);
	mhTickPost = FWorldDelegates::OnWorldPostActorTick.AddRaw(this, &CustomModuleManager::TickPostModules);
}

//----------------------------------------------------------
// StartModules
//----------------------------------------------------------
void CustomModuleManager::StartModules()
{
	for (CustomModuleBase* Module : mpAppModules)
	{
		Module->StartModule();
	}
}

//----------------------------------------------------------
// ShutdownModules
//----------------------------------------------------------
void CustomModuleManager::ShutdownModules()
{
	for (int i = mpAppModules.Num() - 1; i >= 0; i--)
	{
		mpAppModules[i]->DestroyModule();
	}
	mpAppModules.Empty();

	FWorldDelegates::OnWorldPreActorTick.Remove(mhTickPre);
	FWorldDelegates::OnWorldPostActorTick.Remove(mhTickPost);
	mhTickPre.Reset();
	mhTickPost.Reset();
}

//----------------------------------------------------------
// InitGameModules
//----------------------------------------------------------
void CustomModuleManager::InitGameModules()
{
	for (CustomModuleBase* Module : mpAppModules)
	{
		Module->InitGame();
	}
}

//----------------------------------------------------------
// StartPlayModules
//----------------------------------------------------------
void CustomModuleManager::StartPlayModules()
{
	for (CustomModuleBase* Module : mpAppModules)
	{
		Module->StartPlay();
	}
}

//----------------------------------------------------------
// TickPreModules
//----------------------------------------------------------
void CustomModuleManager::TickPreModules(UWorld* pWorld, ELevelTick TickType, float DeltaTime)
{
	if (!pWorld->IsGameWorld())
	{
		return;
	}

	QUICK_SCOPE_CYCLE_COUNTER(CustomModuleManager_TickPreModules);
	for (CustomModuleBase* Module : mpAppModules)
	{
		if (Module->IsEnableUpdate())
		{
			Module->UpdateModule(DeltaTime);
		}
	}
}

//----------------------------------------------------------
// TickPostModules
//----------------------------------------------------------
void CustomModuleManager::TickPostModules(UWorld* pWorld, ELevelTick TickType, float DeltaTime)
{
	if (!pWorld->IsGameWorld())
	{
		return;
	}
	QUICK_SCOPE_CYCLE_COUNTER(CustomModuleManager_TickPostModules);
	for (CustomModuleBase* Module : mpAppModules)
	{
		if (Module->IsEnableUpdate())
		{
			Module->LateUpdateModule(DeltaTime);
		}
	}
}
