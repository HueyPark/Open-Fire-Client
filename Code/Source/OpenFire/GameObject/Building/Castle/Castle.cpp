#include "OpenFire.h"
#include "Castle.h"
#include "GameObject/GameObjectLibrary.h"

const float SpawnDelaySeconds = 1.0f;

ACastle::ACastle()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	SpawnRemainSeconds = SpawnDelaySeconds;

	PrimaryActorTick.bCanEverTick = true;
}

void ACastle::Tick(float DeltaSeconds)
{
	SpawnRemainSeconds -= DeltaSeconds;
	if (SpawnRemainSeconds < 0.0f)
	{
		_SpawnBuilder();

		SpawnRemainSeconds += SpawnDelaySeconds;
	}
}

void ACastle::_SpawnBuilder()
{
	UGameObjectLibrary::SpawnBuilder(GetWorld(), GetActorLocation());
}
