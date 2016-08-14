// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "GameObjectLibrary.h"
#include "GameObject/Unit/Builder/Builder.h"

TSubclassOf<class ABuilder> CLASS_Builder;

UGameObjectLibrary::UGameObjectLibrary()
{
	static ConstructorHelpers::FClassFinder<ABuilder> BUilderBPClass(TEXT("/Game/Blueprint/GameObject/Unit/Builder/BP_Builder"));
	if (BUilderBPClass.Class != nullptr)
	{
		CLASS_Builder = BUilderBPClass.Class;
	}
}

void UGameObjectLibrary::SpawnBuilder(UWorld* InWorld, FVector InLocation)
{
	ABuilder* Builder = InWorld->SpawnActor<ABuilder>(CLASS_Builder, InLocation, FRotator::ZeroRotator);
	if (Builder)
	{
		Builder->SpawnDefaultController();
	}
}
