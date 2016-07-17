#include "OpenFire.h"
#include "StrongPoint.h"
#include "WorldGraph/Graph.h"
#include "WorldGraph/StrongPointData.h"
#include "Network/RestClient.h"
#include "Config/Config.h"

AStrongpoint::AStrongpoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	this->RootComponent = this->staticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Resource/World/Strongpoint/SM_Strongpoint"));
	if(StaticMesh.Succeeded())
	{
		this->staticMeshComponent->SetStaticMesh(StaticMesh.Object);
		this->staticMeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));
		this->staticMeshComponent->OnInputTouchBegin.AddDynamic(this, &AStrongpoint::OnInputTouchBegin);
	}
}

void AStrongpoint::Initialize(const FString id, const int32 level, const Request request)
{
	this->id = id;
	this->level = level;
	this->request = request;

	const int32 materialIndex = 0;
	UMaterialInstanceDynamic* materialInstanceDynamic = UMaterialInstanceDynamic::Create(this->staticMeshComponent->GetMaterial(materialIndex), this);
	materialInstanceDynamic->SetVectorParameterValue("Color", this->_GetColor());
	this->staticMeshComponent->SetMaterial(materialIndex, materialInstanceDynamic);
}

void AStrongpoint::OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent)
{
	FString data = "{\"strongpoint_id\":\"" + this->id + "\"}";
	URestClient::Instance()->Post(Config::GAME_SERVER_URL + "/buildings", data);
}

FLinearColor AStrongpoint::_GetColor()
{
	switch(this->level)
	{
	case 0:
		return FLinearColor(0.65f, 0.553f, 0.0f, 1.0f);
	case 1:
		return FLinearColor(0.851f, 0.718f, 0.0f, 1.0f);
	case 2:
		return FLinearColor(1.0f, 0.843f, 0.0f, 1.0f);
	case 3:
		return FLinearColor(1.0f, 0.914f, 0.439f, 1.0f);
	case 4:
		return FLinearColor(1.0f, 0.98f, 0.75f, 1.0f);
	default:
		return FLinearColor(1.0f, 0.0f, 1.0f, 1.0f);
	}
}
