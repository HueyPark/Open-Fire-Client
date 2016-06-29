#include "OpenFire.h"
#include "WorldGraph.h"
#include "WorldGraph/ObjectData/ObjectData.h"
#include "Network/RestClient.h"
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

void WorldGraph::Initialize(UWorld* world)
{
	this->world = world;
	this->strongPointDatas.Empty();
	this->buildingDatas.Empty();
}

void WorldGraph::OnUpdate()
{
	URestClient::Instance()->Get(Config::GAME_SERVER_URL + "/strongpoints", "", [this](const FString& string)
	{
		StrongPointDTO strongPointDTO = StrongPointDTO(string);

		for (const StrongPointDTO::Data& data : strongPointDTO.datas)
		{
			this->InsertUpdateStrongPointData(data.strongPointID, data.location);
		}
	});

	URestClient::Instance()->Get(Config::GAME_SERVER_URL + "/buildings", "", [this](const FString& string)
	{
		BuildingDTO buildingDTO = BuildingDTO(string);

		for (const BuildingDTO::Data& data : buildingDTO.datas)
		{
			this->InsertUpdateBuildingData(data.buildingID, data.strongPointID);
		}
	});
}

const StrongPointData* WorldGraph::GetStrongPointData(int32 nodeID)
{
	for (StrongPointData& node : this->strongPointDatas)
	{
		if (node.strongPointID == nodeID)
		{
			return &node;
		}
	}

	return nullptr;
}

const TArray<StrongPointData>& WorldGraph::GetStrongPointDatas()
{
	return this->strongPointDatas;
}

const TArray<BuildingData>& WorldGraph::GetBuildingDatas()
{
	return this->buildingDatas;
}

void WorldGraph::InsertUpdateStrongPointData(int32 id, FVector location)
{
	for (StrongPointData& strongpoint : this->strongPointDatas)
	{
		if (strongpoint.strongPointID == id)
		{
			strongpoint.location = location;
			return;
		}
	}

	this->strongPointDatas.Add(StrongPointData(id, location));
}

void WorldGraph::InsertUpdateBuildingData(int32 buildingID, int32 strongpointID)
{
	for (BuildingData& buildingData : this->buildingDatas)
	{
		if (buildingData.buildingID == buildingID)
		{
			return;
		}
	}

	this->buildingDatas.Add(BuildingData(buildingID, strongpointID));
}
