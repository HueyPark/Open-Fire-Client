// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "Environment.h"

// Sets default values
AEnvironment::AEnvironment()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnvironment::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnvironment::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
