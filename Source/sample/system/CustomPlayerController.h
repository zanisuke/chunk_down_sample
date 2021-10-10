// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

//-----------------------------------------------------------------
// CustomPlayerController
//-----------------------------------------------------------------
UCLASS()
class SAMPLE_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACustomPlayerController();

public:
	virtual void BeginPlay() final;
};
