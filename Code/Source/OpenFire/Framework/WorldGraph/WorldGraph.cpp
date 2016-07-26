// Free to use

#include "OpenFire.h"
#include "WorldGraph.h"

#include "Framework/WorldGraph/Model/Strongpoint/StrongpointModel.h"
#include "Framework/WorldGraph/Model/Strongpoint/RoadModel.h"

void UWorldGraph::Init()
{
	for (int32 i = 0; i < 10; ++i)
	{
		UStrongpointModel* StrongpointModel = NewObject<UStrongpointModel>();
		StrongpointModel->Init(
			i,
			FVector(FMath::FRandRange(-1000.0f, 1000.0f), FMath::FRandRange(-1000.0f, 1000.0f), 0.0f)
		);
		this->StrongPointModels.Add(StrongpointModel);
	}
}

void UWorldGraph::OnUpdate()
{
}

const TArray<UStrongpointModel*>& UWorldGraph::GetStrongPointModels()
{
	return this->StrongPointModels;
}
