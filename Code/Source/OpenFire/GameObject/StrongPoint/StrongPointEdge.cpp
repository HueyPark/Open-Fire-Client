// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "StrongPointEdge.h"


// Sets default values
AStrongPointEdge::AStrongPointEdge()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/Sphere"));
	StaticMeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));
	if (StaticMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Game/Resource/Material/Gray"));
	if (Material.Succeeded())
	{
		StaticMeshComponent->SetMaterial(0, Material.Object);
	}
}

// Called when the game starts or when spawned
void AStrongPointEdge::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStrongPointEdge::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
