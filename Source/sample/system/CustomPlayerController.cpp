// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

//-----------------------------------------------------------------
// ctor
//-----------------------------------------------------------------
ACustomPlayerController::ACustomPlayerController()
{
	bShowMouseCursor = true;
}

//-----------------------------------------------------------------
// BeginPlay
//-----------------------------------------------------------------
void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();

#if PLATFORM_WINDOWS
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Type::Default;
#endif
}
