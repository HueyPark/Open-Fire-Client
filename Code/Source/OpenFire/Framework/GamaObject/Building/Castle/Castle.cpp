#include "OpenFire.h"
#include "Castle.h"
#include "Framework/GamaObject/Unit/Builder/Builder.h"

const float SpawnDelaySeconds = 5.0f;

ACastle::ACastle()
{
	this->SpawnRemainSeconds = SpawnDelaySeconds;
}

void ACastle::Tick(float DeltaSeconds)
{
	this->SpawnRemainSeconds -= DeltaSeconds;
	if (this->SpawnRemainSeconds < 0.0f)
	{
		GetWorld()->SpawnActor<ABuilder>(this->CLASS_Builder, this->GetActorLocation(), FRotator::ZeroRotator);
		this->SpawnRemainSeconds += SpawnDelaySeconds;
	}
}
