// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAssetDownloader, Log, All);

//-----------------------------------------------------------------
// AssetDownloader
//-----------------------------------------------------------------
class ASSETDOWNLOADER_API FAssetDownloader : public TSharedFromThis<FAssetDownloader>
{
public:
	struct FChunk;
	struct FPakFile;

	struct FChunk
	{
		int32 ChunkID;
		TArray<TSharedRef<FPakFile>> PakFiles;
	};

	struct FPakFile
	{
		FString FileName;
		FString FileVersion;
		FString RelativeUrl;
		uint64 FileSize = 0;
		int32 ChunkID = -1;
	};

public:
	FAssetDownloader() {};
	~FAssetDownloader() {};

	static TSharedRef<FAssetDownloader> Get();

public:
	void Initialize();
	void Finalize();

	void Sample();

private:
	void DownloadChunkInternal(int32 chunkId);
	void MountChunkInternal(int32 chunkId);

private:
	bool mIsInitialize{};

	FString mRemoteContentDir;
};
