// Free to use

#include "OpenFire.h"
#include "WorldGraph.h"

#include "Framework/WorldGraph/Model/Resource/Resource.h"
#include "Framework/WorldGraph/Model/Strongpoint/StrongpointModel.h"
#include "Framework/WorldGraph/Model/Strongpoint/RoadModel.h"

void UWorldGraph::Init()
{
	for (int32 i = 0; i < 10; ++i)
	{
		UStrongpointModel* StrongpointModel = NewObject<UStrongpointModel>();
		StrongpointModel->Init(
			i,
			FVector(FMath::FRandRange(-2000.0f, 2000.0f), FMath::FRandRange(-2000.0f, 2000.0f), 0.0f)
		);

		UResource* Resource = NewObject<UResource>();
		Resource->Init(FMath::RandRange(1, 10), FMath::RandRange(1, 100));
		StrongpointModel->Resources.Add(Resource);

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
