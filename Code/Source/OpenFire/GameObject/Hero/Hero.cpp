// Free to use

#include "OpenFire.h"
#include "Hero.h"
#include "WorldGraph/Graph.h"
#include "WorldGraph/StrongPointData.h"
#include "WorldGraph/ObjectData/ObjectData.h"

AHero::AHero()
{
	//this->skeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VisualRepresentation"));
	//this->RootComponent = this->skeletalMeshComponent;

	//static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("/Game/Resource/Hero/SM_Hero"));
	//if (skeletalMesh.Succeeded())
	//{
	//	this->skeletalMeshComponent->SetSkeletalMesh(skeletalMesh.Object);
	//}
}

void AHero::Initialize(int32 objectID, FLinearColor color)
{
	Super::Initialize(objectID);

	this->color = color;
}

void AHero::BeginPlay()
{
	this->targetLocation = this->GetActorLocation();

	this->SetColor(this->color);
}

void AHero::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	auto currentLocation = this->GetActorLocation();

	this->SetActorLocation(FMath::VInterpTo(currentLocation, this->targetLocation, deltaSeconds, 1.0f));
}

void AHero::CheckObjectData()
{
}

void AHero::SetColor(FLinearColor color)
{
	UMaterialInstanceDynamic* materialInstanceDynamic = UMaterialInstanceDynamic::Create(this->skeletalMeshComponent->GetMaterial(0), this);
	materialInstanceDynamic->SetVectorParameterValue("Color", color);
	this->skeletalMeshComponent->SetMaterial(0, materialInstanceDynamic);
}
