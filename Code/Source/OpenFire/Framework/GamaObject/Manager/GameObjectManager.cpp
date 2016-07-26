// Free to use

#include "OpenFire.h"
#include "GameObjectManager.h"

#include "Framework/WorldGraph/Model/Strongpoint/StrongpointModel.h"
#include "Framework/WorldGraph/WorldGraph.h"
#include "GameObject/Strongpoint/Strongpoint.h"
#include "WorldGraph/Graph.h"

void UGameObjectManager::Init(UWorld* world, UWorldGraph* WorldGraph)
{
	this->world = world;
	this->WorldGraph = WorldGraph;
}

void UGameObjectManager::OnUpdate()
{
	this->_UpdateStrongPoints();
}

void UGameObjectManager::_SpawnStrongPoint(const int32 Id, const FVector Location, const int32 Level)
{
	AStrongpoint* StrongPoint = this->world->SpawnActor<AStrongpoint>(CLASS_Strongpoint, Location, FRotator::ZeroRotator);
	StrongPoint->Init(Id, Level);

	this->StrongPointMap.Add(Id, StrongPoint);
}

void UGameObjectManager::_UpdateStrongPoints()
{
	for (const UStrongpointModel* Model : this->WorldGraph->GetStrongPointModels())
	{
		if (this->StrongPointMap.Find(Model->Id) == nullptr)
		{
			this->_SpawnStrongPoint(Model->Id, Model->Location, 1);
		}
	}
}
