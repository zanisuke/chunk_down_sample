// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameModeBase.h"
#include "CustomGameInstance.h"
#include "CustomPlayerController.h"

//-----------------------------------------------------------------
// ctor
//-----------------------------------------------------------------
ACustomGameModeBase::ACustomGameModeBase()
{
	bNetLoadOnClient = false;
	bPauseable = true;
	bStartPlayersAsSpectators = false;

	PlayerControllerClass = ACustomPlayerController::StaticClass();
}

//-----------------------------------------------------------------
// InitGame
//-----------------------------------------------------------------
void ACustomGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UCustomGameInstance::GetInstance().InitGame();
}

//-----------------------------------------------------------------
// StartPlay
//-----------------------------------------------------------------
void ACustomGameModeBase::StartPlay()
{
	Super::StartPlay();

	UCustomGameInstance::GetInstance().StartPlay();
}

//-----------------------------------------------------------------
// BeginPlay
//-----------------------------------------------------------------
void ACustomGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

//-----------------------------------------------------------------
// EndPlay
//-----------------------------------------------------------------
void ACustomGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
