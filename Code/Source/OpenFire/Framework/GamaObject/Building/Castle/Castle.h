#pragma once

#include "GameObject/Building/Building.h"
#include "Castle.generated.h"

class ADino;

UCLASS()
class OPENFIRE_API ACastle : public ABuilding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ADino> CLASS_Dino;

private:
	float SpawnRemainSeconds;

public:
	ACastle();

	virtual void Tick(float DeltaSeconds) override;
};
