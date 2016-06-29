#include "OpenFire.h"
#include "Mine.h"

AMine::AMine()
{
	UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/Building/Mine/SM_Mine"));
	if (StaticMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
	}
}
