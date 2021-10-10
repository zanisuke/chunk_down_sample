// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../system/CustomModuleBase.h"

//-----------------------------------------------------------------
// CustomManager
//-----------------------------------------------------------------
class SAMPLE_API CustomManager final : public CustomModuleBase
{
public:
	CustomManager();
	~CustomManager();

	static CustomManager& GetInstance() { return Singleton<CustomManager>::GetInstance(); }

public:
	void StartModule() override;
	void UpdateModule(float dt) override;
	void DestroyModule() override;

public:
	void Sample();

};
