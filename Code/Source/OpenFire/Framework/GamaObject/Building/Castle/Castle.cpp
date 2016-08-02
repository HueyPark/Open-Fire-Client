#include "OpenFire.h"
#include "Castle.h"
#include "Framework/GamaObject/Unit/Dino/Dino.h"

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
		GetWorld()->SpawnActor<ADino>(this->CLASS_Dino, this->GetActorLocation(), FRotator::ZeroRotator);
		this->SpawnRemainSeconds += SpawnDelaySeconds;
	}
}
