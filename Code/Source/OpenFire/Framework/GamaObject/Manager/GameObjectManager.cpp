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

void UGameObjectManager::_SpawnStrongPoint(const UStrongpointModel* Model)
{
	AStrongpoint* StrongPoint = this->world->SpawnActor<AStrongpoint>(CLASS_Strongpoint, Model->Location, FRotator::ZeroRotator);
	StrongPoint->Init(Model);

	this->StrongPointMap.Add(Model->Id, StrongPoint);
}

void UGameObjectManager::_UpdateStrongPoints()
{
	for (const UStrongpointModel* Model : this->WorldGraph->GetStrongPointModels())
	{
		if (this->StrongPointMap.Find(Model->Id) == nullptr)
		{
			this->_SpawnStrongPoint(Model);
		}
	}
}
