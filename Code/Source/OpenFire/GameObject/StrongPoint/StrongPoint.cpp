#include "OpenFire.h"
#include "StrongPoint.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"
#include "Network/RestClient.h"
#include "Config/Config.h"

AStrongPoint::AStrongPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = this->staticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/StaticMesh/StrongPoint"));
	if (StaticMesh.Succeeded())
	{
		this->staticMeshComponent->SetStaticMesh(StaticMesh.Object);
		this->staticMeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));
		this->staticMeshComponent->OnInputTouchBegin.AddDynamic(this, &AStrongPoint::OnInputTouchBegin);
	}
}

void AStrongPoint::Initialize(int32 strongPointID)
{
	this->strongPointID = strongPointID;
}

void AStrongPoint::OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent)
{
	FString data = "{\"strongpoint_id\":\"" + FString::FromInt(this->strongPointID) + "\"}";
	URestClient::Instance()->Post(Config::GAME_SERVER_URL + "/buildings", data);
}
