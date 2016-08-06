// Free to use

#include "OpenFire.h"
#include "Dino.h"


// Sets default values
ADino::ADino()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADino::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADino::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void ADino::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}
