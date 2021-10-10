// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"
#include "MainUserWidget.generated.h"

//-----------------------------------------------------------------
// MainUserWidget
//-----------------------------------------------------------------
UCLASS()
class SAMPLE_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

public:
	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	void OnSampleButtonClicked();

	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	void OnUpdateTexture1ButtonClicked();

	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	void OnUpdateTexture2ButtonClicked();

	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	void OnUpdateTexture3ButtonClicked();

private:
	UPROPERTY()
	UImage* mpSampleImage {};
};
