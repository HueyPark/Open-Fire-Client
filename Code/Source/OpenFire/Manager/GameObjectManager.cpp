#include "OpenFire.h"
#include "GameObjectManager.h"
#include "WorldGraph/WorldGraph.h"
#include "WorldGraph/StrongPointData.h"
#include "GameObject/StrongPoint/StrongPoint.h"
#include "GameObject/Building/Building.h"
#include "GameObject/Building/Castle.h"
#include "WorldGraph/ObjectData/ObjectData.h"

void GameObjectManager::Initialize(UWorld* world)
{
	this->world = world;
	this->strongPointMap.Empty();
	this->buildingMap.Empty();
}

void GameObjectManager::OnUpdate()
{
	this->UpdateStrongPoints();
	this->UpdateBuildings();
}

void GameObjectManager::SpawnStrongPoint(int32 nodeID, FVector location)
{
	AStrongPoint* strongPoint = this->world->SpawnActor<AStrongPoint>(location, FRotator::ZeroRotator);
	strongPoint->Initialize(nodeID);

	this->strongPointMap.Add(nodeID, strongPoint);
}

void GameObjectManager::SpawnBuilding(int32 buildingID, int32 strongPointID, ObjectDataType type)
{
	const StrongPointData* strongPointData = WorldGraph::Instance()->GetStrongPointData(strongPointID);
	if (strongPointData == nullptr)
	{
		return;
	}

	ACastle* building = this->world->SpawnActor<ACastle>(strongPointData->location, FRotator::ZeroRotator);
	building->Initialize(buildingID);

	this->buildingMap.Add(buildingID, building);
}

void GameObjectManager::UpdateStrongPoints()
{
	for (const StrongPointData& strongPointData : WorldGraph::Instance()->GetStrongPointDatas())
	{
		if (this->strongPointMap.Find(strongPointData.strongPointID) == nullptr)
		{
			this->SpawnStrongPoint(strongPointData.strongPointID, strongPointData.location);
		}
	}
}

void GameObjectManager::UpdateBuildings()
{
	for (const BuildingData& buildingData : WorldGraph::Instance()->GetBuildingDatas())
	{
		if (this->buildingMap.Find(buildingData.buildingID) == nullptr)
		{
			this->SpawnBuilding(buildingData.buildingID, buildingData.strongPointID, ObjectDataType::Building);
		}
	}
}
