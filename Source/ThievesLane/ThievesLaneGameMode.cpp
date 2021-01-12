// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThievesLaneGameMode.h"
#include "ThievesLaneHUD.h"
#include "ThievesLaneCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThievesLaneGameMode::AThievesLaneGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AThievesLaneHUD::StaticClass();
}
