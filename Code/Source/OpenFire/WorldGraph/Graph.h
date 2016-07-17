#pragma once

#include "Framework/Singleton.h"
#include "WorldGraph/StrongPointData.h"
#include "WorldGraph/ObjectData/BuildingData.h"

class MissionValues;
enum class ObjectDataType;
enum class Request;

namespace World
{

class OPENFIRE_API Graph : public Singleton<Graph>
{
private:
	UWorld* world = nullptr;

	TArray<Strongpoint> strongpoints;
	TArray<BuildingData> buildingDatas;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

	const Strongpoint* GetStrongPointData(int32 nodeID);

	const TArray<Strongpoint>& GetStrongPointDatas();
	const TArray<BuildingData>& GetBuildingDatas();

	void InsertUpdateStrongPointData(const FString id, const FVector location, const int32 level, const Request request);
	void InsertUpdateBuildingData(int32 buildingID, int32 strongpointID);
};

}
