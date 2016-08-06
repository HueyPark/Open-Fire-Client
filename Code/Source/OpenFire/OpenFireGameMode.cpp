// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "OpenFirePlayerController.h"
#include "OpenFireCharacter.h"

AOpenFireGameMode::AOpenFireGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AOpenFirePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}