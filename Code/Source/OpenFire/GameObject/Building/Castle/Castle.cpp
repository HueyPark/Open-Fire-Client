#include "OpenFire.h"
#include "Castle.h"
#include "../../Unit/Builder/Builder.h"

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
	ABuilder* Builder = GetWorld()->SpawnActor<ABuilder>(CLASS_Builder, GetActorLocation(), FRotator::ZeroRotator);
	if (Builder)
	{
		Builder->SpawnDefaultController();
	}
}
