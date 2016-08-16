// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "GameObjectLibrary.generated.h"

UCLASS()
class OPENFIRE_API UGameObjectLibrary : public UObject
{
	GENERATED_BODY()

public:
	UGameObjectLibrary();

	static void SpawnBuilder(UWorld* InWorld, const FVector InLocation);
	static void SpawnTree(UWorld* InWorld, const FVector InLocation);

private:
	static const FVector _GetSpawnLocation(const FVector InLocation);
};
