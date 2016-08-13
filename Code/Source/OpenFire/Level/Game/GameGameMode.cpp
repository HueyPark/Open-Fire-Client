// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "OpenFire.h"
#include "GameGameMode.h"
#include "GameObject/User/UserController.h"

AGameGameMode::AGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUserController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/GameObject/User/BP_User"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}