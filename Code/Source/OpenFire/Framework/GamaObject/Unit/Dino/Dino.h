// Free to use

#pragma once

#include "GameFramework/Character.h"
#include "Dino.generated.h"

UCLASS()
class OPENFIRE_API ADino : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADino();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
