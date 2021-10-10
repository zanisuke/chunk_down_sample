// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"

#include "Singleton.h"
#include "CustomModuleBase.h"
#include "../manager/CustomManager.h"

UCustomGameInstance* UCustomGameInstance::s_mpInstance = nullptr;

//-----------------------------------------------------------------
// Init
//-----------------------------------------------------------------
void UCustomGameInstance::Init()
{
	Super::Init();

	UCustomGameInstance::s_mpInstance = this;

	Singleton<CustomModuleManager>::Create();
	Singleton<CustomManager>::Create();

	CustomModuleManager::GetInstance().InitModules(this);
	CustomModuleManager::GetInstance().StartModules();
}

//-----------------------------------------------------------------
// Shutdown
//-----------------------------------------------------------------
void UCustomGameInstance::Shutdown()
{
	Super::Shutdown();

	CustomModuleManager::GetInstance().ShutdownModules();
	SingletonFinalizer::Finalize();
}

//-----------------------------------------------------------------
// InitGame
//-----------------------------------------------------------------
void UCustomGameInstance::InitGame()
{
	CustomModuleManager::GetInstance().InitGameModules();
}

//-----------------------------------------------------------------
// StartPlay
//-----------------------------------------------------------------
void UCustomGameInstance::StartPlay()
{
	CustomModuleManager::GetInstance().StartPlayModules();
}
