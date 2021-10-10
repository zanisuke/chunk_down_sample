// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CustomGameModeBase.generated.h"

//-----------------------------------------------------------------
// CustomGameModeBase
//-----------------------------------------------------------------
UCLASS()
class SAMPLE_API ACustomGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACustomGameModeBase();

public:
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	void StartPlay() override;
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
