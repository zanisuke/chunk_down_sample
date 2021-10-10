// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetDownloader.h"
#include "AssetDownloaderModule.h"

DEFINE_LOG_CATEGORY(LogAssetDownloader);

static const FName AssetDownloaderModuleName = "AssetDownloader";

TSharedRef<FAssetDownloader> FAssetDownloader::Get()
{
	FAssetDownloaderModule& module = FModuleManager::LoadModuleChecked<FAssetDownloaderModule>(AssetDownloaderModuleName);
	if (!module.AssetDownloader.IsValid())
	{
		module.AssetDownloader = MakeShareable(new FAssetDownloader());
	}
	return module.AssetDownloader.ToSharedRef();
}

void FAssetDownloader::Initialize()
{
	IFileManager& rFileManager = IFileManager::Get();
	mRemoteContentDir = FPaths::Combine(FPaths::ProjectPersistentDownloadDir(), TEXT("RemoteContent"));
	if (!rFileManager.MakeDirectory(*mRemoteContentDir, true))
	{
		UE_LOG(LogAssetDownloader, Error, TEXT("Failed Make Remote Content Directory"));
	}
	FPlatformMisc::AddAdditionalRootDirectory(mRemoteContentDir);

	mIsInitialize = true;
}

void FAssetDownloader::Finalize()
{
}

void FAssetDownloader::Sample()
{
	IFileManager& rFileManager = IFileManager::Get();
	TArray<FString> pakFiles;
	rFileManager.FindFiles(pakFiles, *mRemoteContentDir, TEXT("*.pak"));
	for (int i = 0; i < pakFiles.Num(); i++)
	{
		if (FCoreDelegates::OnMountPak.IsBound())
		{
			bool bMountSuccess = FCoreDelegates::OnMountPak.Execute(FPaths::Combine(mRemoteContentDir, pakFiles[i]), i, nullptr);
			if (bMountSuccess)
			{
				UE_LOG(LogAssetDownloader, Log, TEXT("Success Mount: %s"), *pakFiles[i]);
			}
			else
			{
				UE_LOG(LogAssetDownloader, Error, TEXT("Failed Mount: %s"), *pakFiles[i]);
			}
		}
	}
}
