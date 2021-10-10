// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomManager.h"
#include "AssetDownloader.h"

//-----------------------------------------------------------------
// ctor
//-----------------------------------------------------------------
CustomManager::CustomManager()
{
	TSharedRef<FAssetDownloader> downloader = FAssetDownloader::Get();
	downloader->Initialize();
}

//-----------------------------------------------------------------
// dtor
//-----------------------------------------------------------------
CustomManager::~CustomManager()
{
}

//-----------------------------------------------------------------
// StartModule
//-----------------------------------------------------------------
void CustomManager::StartModule()
{
}

//-----------------------------------------------------------------
// UpdateModule
//-----------------------------------------------------------------
void CustomManager::UpdateModule(float dt)
{
}

//-----------------------------------------------------------------
// DestroyModule
//-----------------------------------------------------------------
void CustomManager::DestroyModule()
{
}

//-----------------------------------------------------------------
// Sample
//-----------------------------------------------------------------
void CustomManager::Sample()
{
	TSharedRef<FAssetDownloader> downloader = FAssetDownloader::Get();
	downloader->Sample();
}
