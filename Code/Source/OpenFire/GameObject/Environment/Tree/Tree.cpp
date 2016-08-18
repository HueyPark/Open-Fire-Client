// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Tree.h"

ATree::ATree()
{
	Size = 0.0f;
}

void ATree::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	Size += DeltaSeconds;

	StaticMeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, Size));
}
