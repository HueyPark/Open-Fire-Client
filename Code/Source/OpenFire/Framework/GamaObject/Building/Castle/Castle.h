#pragma once

#include "GameObject/Building/Building.h"
#include "Castle.generated.h"

class ABuilder;

UCLASS()
class OPENFIRE_API ACastle : public ABuilding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ABuilder> CLASS_Builder;

private:
	float SpawnRemainSeconds;

public:
	ACastle();

	virtual void Tick(float DeltaSeconds) override;
};
