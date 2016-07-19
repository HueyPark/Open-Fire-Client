#include "OpenFire.h"
//#include "GameObjectManager.h"
//#include "WorldGraph/Graph.h"
//#include "WorldGraph/StrongPointData.h"
//#include "GameObject/Building/Building.h"
//#include "GameObject/Building/Castle.h"
//#include "GameObject/Strongpoint/Strongpoint.h"
//#include "WorldGraph/ObjectData/ObjectData.h"
//
//void GameObjectManager::Initialize(UWorld* world)
//{
//	this->world = world;
//	this->strongpointMap.Empty();
//	this->buildingMap.Empty();
//}
//
//void GameObjectManager::OnUpdate()
//{
//	this->UpdateStrongPoints();
//	this->UpdateBuildings();
//}
//
//void GameObjectManager::SpawnStrongPoint(const FString id, const FVector location, const int32 level, const Request request)
//{
//	AStrongpoint* strongPoint = this->world->SpawnActor<AStrongpoint>(location, FRotator::ZeroRotator);
//	strongPoint->Initialize(id, level, request);
//
//	this->strongpointMap.Add(id, strongPoint);
//}
//
//void GameObjectManager::SpawnBuilding(int32 buildingID, int32 strongPointID, ObjectDataType type)
//{
//	const World::Strongpoint* strongPointData = World::Graph::Instance()->GetStrongPointData(strongPointID);
//	if (strongPointData == nullptr)
//	{
//		return;
//	}
//
//	ACastle* building = this->world->SpawnActor<ACastle>(strongPointData->location, FRotator::ZeroRotator);
//	building->Initialize(buildingID);
//
//	this->buildingMap.Add(buildingID, building);
//}
//
//void GameObjectManager::UpdateStrongPoints()
//{
//	for (const World::Strongpoint& strongpoint : World::Graph::Instance()->GetStrongPointDatas())
//	{
//		if (this->strongpointMap.Find(strongpoint.id) == nullptr)
//		{
//			this->SpawnStrongPoint(strongpoint.id, strongpoint.location, strongpoint.level, strongpoint.request);
//		}
//	}
//}
//
//void GameObjectManager::UpdateBuildings()
//{
//	for (const BuildingData& buildingData : World::Graph::Instance()->GetBuildingDatas())
//	{
//		if (this->buildingMap.Find(buildingData.buildingID) == nullptr)
//		{
//			this->SpawnBuilding(buildingData.buildingID, buildingData.strongPointID, ObjectDataType::Building);
//		}
//	}
//}