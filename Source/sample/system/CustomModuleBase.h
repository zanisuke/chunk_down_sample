// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Singleton.h"

class UGameInstance;
class UCustomGameInstance;

//-----------------------------------------------------------------
// CustomModuleBase
//-----------------------------------------------------------------
class CustomModuleBase
{
	friend class CustomModuleManager;

public:
	CustomModuleBase();
	virtual ~CustomModuleBase(){};

public:
	virtual void StartModule() = 0;
	virtual void UpdateModule(float dt) = 0;
	virtual void DestroyModule() = 0;
	virtual void LateUpdateModule(float dt) {};

	virtual void InitGame() {}
	virtual void StartPlay() {}


public:
	UWorld* GetWorld() const;
	void SetOwnerInstance(UGameInstance* owner) { mpOwnerInstance = owner; }

	bool IsEnableUpdate() const { return mEnableUpdate; }

protected:
	bool mEnableUpdate{ true };

private:
	UGameInstance* mpOwnerInstance{};
};

//-----------------------------------------------------------------
// CustomModuleManager
//-----------------------------------------------------------------
class CustomModuleManager
{
	friend class UWorldGameInstance;
public:
	CustomModuleManager(){};
	virtual ~CustomModuleManager(){};

	static CustomModuleManager& GetInstance() { return Singleton<CustomModuleManager>::GetInstance(); }

	void AddModule(CustomModuleBase* pModule);
	void InitModules(UGameInstance* pOwner);
	void StartModules();
	void ShutdownModules();
	void InitGameModules();
	void StartPlayModules();

public:
	// Delegate
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnLoadComplete, const float, const FString&);
	FOnLoadComplete OnLoadComplete;

private:
	void TickPreModules(UWorld* World, ELevelTick TickType, float DeltaTime);
	void TickPostModules(UWorld* World, ELevelTick TickType, float DeltaTime);

private:
	TArray<CustomModuleBase*> mpAppModules{};
	FDelegateHandle mhTickPre{};
	FDelegateHandle mhTickPost{};
};
