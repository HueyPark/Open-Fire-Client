// Free to use

#pragma once

#include "GameFramework/Character.h"
#include "Framework/GamaObject/Unit/Unit.h"
#include "Builder.generated.h"

UCLASS()
class OPENFIRE_API ABuilder : public AUnit
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABuilder();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
