#include "OpenFire.h"
#include "StrongPoint.h"

#include "Framework/WorldGraph/Model/Strongpoint/StrongpointModel.h"


AStrongpoint::AStrongpoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AStrongpoint::Init(const UStrongpointModel* Model)
{
	this->Model = Model;

	this->PostInit();
}

FLinearColor AStrongpoint::_GetColor()
{
	switch(this->Model->Level)
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
