#include "OpenFire.h"
#include "Castle.h"

ACastle::ACastle()
{
	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/Castle"));
	if (StaticMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
	}
}
