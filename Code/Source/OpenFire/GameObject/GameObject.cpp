// Free to use

#include "OpenFire.h"
#include "GameObject.h"

const float updateSeconds = 1.0f;

// Sets default values
AGameObject::AGameObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGameObject::Initialize(int32 objectID)
{
	this->objectID = objectID;
}

// Called when the game starts or when spawned
void AGameObject::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameObject::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	this->accumulatedSeconds += deltaSeconds;
	if (this->accumulatedSeconds > updateSeconds)
	{
		this->accumulatedSeconds -= updateSeconds;
		this->CheckObjectData();
	}
}

void AGameObject::CheckObjectData()
{
}
