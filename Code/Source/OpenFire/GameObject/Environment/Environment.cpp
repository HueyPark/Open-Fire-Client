// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Environment.h"

AEnvironment::AEnvironment()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetSimulatePhysics(true);
	FBodyInstance* BodyInstance = StaticMeshComponent->GetBodyInstance();
	BodyInstance->bLockXRotation = true;
	BodyInstance->bLockYRotation = true;
	BodyInstance->bLockZRotation = true;
	RootComponent = StaticMeshComponent;

	PrimaryActorTick.bCanEverTick = true;
}
