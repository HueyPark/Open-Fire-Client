#pragma once

#include "Castle.generated.h"

class ABuilder;

UCLASS()
class OPENFIRE_API ACastle : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ABuilder> CLASS_Builder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* StaticMeshComponent;

private:
	float SpawnRemainSeconds;

public:
	ACastle();

	virtual void Tick(float DeltaSeconds) override;

private:
	void _SpawnBuilder();
};
