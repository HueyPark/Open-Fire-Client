#include "OpenFire.h"
#include "WorldGraph.h"
#include "WorldGraph/ObjectData/ObjectData.h"
#include "Network/RestClient.h"
#include "Network/DTO/IslandDTO.h"
#include "Network/DTO/StrongPointDTO.h"
#include "Network/DTO/BuildingDTO.h"
#include "Type/MissionType.h"
#include "GameObject/Building/Mine.h"
#include "GameObject/Building/Farm.h"
#include "GameObject/Building/Castle.h"
#include "GameObject/Unit/Worker.h"
#include "GameObject/Hero/Hero.h"
#include "GameObject/Resource/Gold.h"
#include "Config/Config.h"

namespace World
{

void WorldGraph::Initialize(UWorld* world)
{
	this->world = world;
	this->strongpoints.Empty();
	this->buildingDatas.Empty();
}

void WorldGraph::OnUpdate()
{
	URestClient::Instance()->Get(Config::GAME_SERVER_URL + "/islands", "", [this](const FString& string)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), &string);
		DTO::Island island = DTO::Island(string);

		for(const DTO::Island::Strongpoint& strongpoint : island.strongpoints)
		{
			this->InsertUpdateStrongPointData(strongpoint.id, strongpoint.location);
		}
	});
}

const Strongpoint* WorldGraph::GetStrongPointData(int32 nodeID)
{
	// TODO: Implementation
	//for(StrongPointData& node : this->strongPointDatas)
	//{
	//	if(node.strongPointID == nodeID)
	//	{
	//		return &node;
	//	}
	//}

	return nullptr;
}

const TArray<Strongpoint>& WorldGraph::GetStrongPointDatas()
{
	return this->strongpoints;
}

const TArray<BuildingData>& WorldGraph::GetBuildingDatas()
{
	return this->buildingDatas;
}

void WorldGraph::InsertUpdateStrongPointData(const FString id, const FVector location)
{
	for(Strongpoint& strongpoint : this->strongpoints)
	{
		if(strongpoint.id == id)
		{
			strongpoint.location = location;
			return;
		}
	}

	this->strongpoints.Add(Strongpoint(id, location));
}

void WorldGraph::InsertUpdateBuildingData(int32 buildingID, int32 strongpointID)
{
	for(BuildingData& buildingData : this->buildingDatas)
	{
		if(buildingData.buildingID == buildingID)
		{
			return;
		}
	}

	this->buildingDatas.Add(BuildingData(buildingID, strongpointID));
}

}
