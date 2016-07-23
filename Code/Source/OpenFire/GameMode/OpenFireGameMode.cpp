// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "OpenFireGameMode.h"
#include "OpenFirePlayerController.h"
#include "Framework/GamaObject/Manager/GameObjectManager.h"
#include "Framework/WorldGraph/WorldGraph.h"
#include "GameObject/StrongPoint/StrongPoint.h"
#include "GameObject/StrongPoint/StrongPointEdge.h"
#include "Manager/TimeManager.h"

const float updateSeconds = 5.0f;

AOpenFireGameMode::AOpenFireGameMode()
{
	this->PlayerControllerClass = AOpenFirePlayerController::StaticClass();
}

void AOpenFireGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	this->gameObjectManager = NewObject<UGameObjectManager>(UGameObjectManager::StaticClass());
	this->gameObjectManager->Init(this->GetWorld());

	this->worldGraph = NewObject<UWorldGraph>(UWorldGraph::StaticClass());
}

void AOpenFireGameMode::Tick(float DeltaSeconds)
{
	TimeManager::Instance()->AddSeconds(DeltaSeconds);

	float remainingSeconds = TimeManager::Instance()->GetRemainingSeconds();
	if (remainingSeconds < 0.0f)
	{
		TimeManager::Instance()->RewindSeconds();

		this->gameObjectManager->OnUpdate();
	}
}
