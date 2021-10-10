// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUserWidget.h"
#include "../manager/CustomManager.h"

bool UMainUserWidget::Initialize()
{
	bool bSuccess = Super::Initialize();
	UPanelWidget* panel = Cast<UPanelWidget>(this->GetRootWidget());
	TArray<UWidget*> childWidgets = panel->GetAllChildren();
	for (int i = 0; i < childWidgets.Num(); i++)
	{
		if (childWidgets[i]->GetClass() == UImage::StaticClass())
		{
			if (childWidgets[i]->GetName() == TEXT("SampleImage"))
			{
				mpSampleImage = Cast<UImage>(childWidgets[i]);
			}
		}
	}

	return bSuccess;
}

void UMainUserWidget::OnSampleButtonClicked()
{
	CustomManager::GetInstance().Sample();
	UE_LOG(LogTemp, Log, TEXT("Sample"));
}

void UMainUserWidget::OnUpdateTexture1ButtonClicked()
{
	if (mpSampleImage != nullptr)
	{
		UTexture2D* dl01 = LoadObject<UTexture2D>(NULL, TEXT("/Game/dl_content/dl01/dl_01.dl_01"), NULL, LOAD_None, NULL);
		if (dl01 != nullptr)
		{
			mpSampleImage->SetBrushFromTexture(dl01);
		}
	}
}

void UMainUserWidget::OnUpdateTexture2ButtonClicked()
{
	if (mpSampleImage != nullptr)
	{
		UTexture2D* dl02 = LoadObject<UTexture2D>(NULL, TEXT("/Game/dl_content/dl02/dl_02.dl_02"), NULL, LOAD_None, NULL);
		if (dl02 != nullptr)
		{
			mpSampleImage->SetBrushFromTexture(dl02);
		}
	}
}

void UMainUserWidget::OnUpdateTexture3ButtonClicked()
{
	if (mpSampleImage != nullptr)
	{
		UTexture2D* dl03 = LoadObject<UTexture2D>(NULL, TEXT("/Game/dl_content/dl03/dl_03.dl_03"), NULL, LOAD_None, NULL);
		if (dl03 != nullptr)
		{
			mpSampleImage->SetBrushFromTexture(dl03);
		}
	}
}
