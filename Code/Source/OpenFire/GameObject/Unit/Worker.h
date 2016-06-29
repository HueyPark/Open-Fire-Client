// Free to use

#pragma once

#include "GameObject/GameObject.h"
#include "Worker.generated.h"

UCLASS()
class OPENFIRE_API AWorker : public AGameObject
{
	GENERATED_BODY()
private:
	FVector targetLocation = FVector::ZeroVector;

public:
	AWorker();

	virtual void BeginPlay() override;

	virtual void Tick(float deltaSeconds) override;

	virtual void CheckObjectData() override;
};
