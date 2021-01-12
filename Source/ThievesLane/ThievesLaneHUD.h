// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ThievesLaneHUD.generated.h"

UCLASS()
class AThievesLaneHUD : public AHUD
{
	GENERATED_BODY()

public:
	AThievesLaneHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

