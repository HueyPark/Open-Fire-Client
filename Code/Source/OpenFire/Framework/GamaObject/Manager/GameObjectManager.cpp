// Free to use

#include "OpenFire.h"
#include "GameObjectManager.h"

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

void UGameObjectManager::_SpawnStrongPoint(const FString id, const FVector location, const int32 level, const Request request)
{
	AStrongpoint* strongPoint = this->world->SpawnActor<AStrongpoint>(CLASS_Strongpoint, location, FRotator::ZeroRotator);
	strongPoint->Init(id, level, request);

	this->strongpointMap.Add(id, strongPoint);
}

void UGameObjectManager::_UpdateStrongPoints()
{
	for (const World::Strongpoint& strongpoint : World::Graph::Instance()->GetStrongPointDatas())
	{
		if (this->strongpointMap.Find(strongpoint.id) == nullptr)
		{
			this->_SpawnStrongPoint(strongpoint.id, strongpoint.location, strongpoint.level, strongpoint.request);
		}
	}
}
