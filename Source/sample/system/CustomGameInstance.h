// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomGameInstance.generated.h"

//-----------------------------------------------------------------
// CustomGameInstance
//-----------------------------------------------------------------
UCLASS()
class SAMPLE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void Shutdown() override;
	
public:
	static UCustomGameInstance& GetInstance() { return *(s_mpInstance); }

	void InitGame();
	void StartPlay();

private:
	static UCustomGameInstance* s_mpInstance;
};
