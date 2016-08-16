// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "GameObjectLibrary.h"

#include "GameObject/Environment/Tree/Tree.h"
#include "GameObject/Unit/Builder/Builder.h"

const float SPAWN_OFFSET_Z = 200.0f;

TSubclassOf<ATree> CLASS_Tree;
TSubclassOf<ABuilder> CLASS_Builder;

UGameObjectLibrary::UGameObjectLibrary()
{
	static ConstructorHelpers::FClassFinder<ATree> TreeBpClass(TEXT("/Game/Blueprint/GameObject/Environment/Tree/BP_Tree"));
	if (TreeBpClass.Class != nullptr)
	{
		CLASS_Tree = TreeBpClass.Class;
	}

	static ConstructorHelpers::FClassFinder<ABuilder> BuilderBpClass(TEXT("/Game/Blueprint/GameObject/Unit/Builder/BP_Builder"));
	if (BuilderBpClass.Class != nullptr)
	{
		CLASS_Builder = BuilderBpClass.Class;
	}
}

void UGameObjectLibrary::SpawnBuilder(UWorld* InWorld, const FVector InLocation)
{
	ABuilder* Builder = InWorld->SpawnActor<ABuilder>(CLASS_Builder, _GetSpawnLocation(InLocation), FRotator::ZeroRotator);
	if (Builder)
	{
		Builder->SpawnDefaultController();
	}
}

void UGameObjectLibrary::SpawnTree(UWorld* InWorld, const FVector InLocation)
{
	InWorld->SpawnActor<ATree>(CLASS_Tree, _GetSpawnLocation(InLocation), FRotator::ZeroRotator);
}

const FVector UGameObjectLibrary::_GetSpawnLocation(const FVector InLocation)
{
	FVector SpawnLocation(InLocation.X, InLocation.Y, InLocation.Z + SPAWN_OFFSET_Z);
	return SpawnLocation;
}
