// Free to use

#include "OpenFire.h"
#include "Worker.h"
#include "WorldGraph/Graph.h"
#include "WorldGraph/StrongPointData.h"

AWorker::AWorker()
{
	//// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	//this->RootComponent = StaticMeshComponent;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/Worker"));
	//if (StaticMesh.Succeeded())
	//{
	//	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
	//	StaticMeshComponent->SetWorldScale3D(FVector(1.0f, 1.0f, 2.0f));
	//	StaticMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	//}
}

void AWorker::BeginPlay()
{
	this->targetLocation = this->GetActorLocation();
}

void AWorker::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	auto currentLocation = this->GetActorLocation();

	this->SetActorLocation(FMath::VInterpTo(currentLocation, this->targetLocation, deltaSeconds, 1.0f));
}

void AWorker::CheckObjectData()
{
}
