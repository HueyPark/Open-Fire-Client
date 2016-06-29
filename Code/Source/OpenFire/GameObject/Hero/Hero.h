// Free to use

#pragma once

#include "GameObject/GameObject.h"
#include "Hero.generated.h"

UCLASS()
class OPENFIRE_API AHero : public AGameObject
{
	GENERATED_BODY()

private:
	USkeletalMeshComponent* skeletalMeshComponent;
	FLinearColor color = FLinearColor::Red;

	FVector targetLocation = FVector::ZeroVector;

public:
	AHero();

	void Initialize(int32 objectID, FLinearColor color);

	virtual void BeginPlay() override;

	virtual void Tick(float deltaSeconds) override;

	virtual void CheckObjectData() override;

private:
	void SetColor(FLinearColor color);
};
