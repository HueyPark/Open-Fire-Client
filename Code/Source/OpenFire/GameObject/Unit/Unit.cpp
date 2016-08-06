// Free to use

#include "OpenFire.h"
#include "Unit.h"

// Sets default values
AUnit::AUnit()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UCapsuleComponent* CapsuleComponent = GetCapsuleComponent();
	CapsuleComponent->InitCapsuleSize(50.0f, 100.0f);

	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -100.0f));
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUnit::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void AUnit::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}
