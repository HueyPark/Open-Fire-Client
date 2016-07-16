#pragma once

#include "Framework/Singleton.h"
#include "WorldGraph/StrongPointData.h"
#include "WorldGraph/ObjectData/BuildingData.h"

class MissionValues;
enum class ObjectDataType;

namespace World
{

class OPENFIRE_API WorldGraph : public Singleton<WorldGraph>
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

	void InsertUpdateStrongPointData(const FString id, const FVector location);
	void InsertUpdateBuildingData(int32 buildingID, int32 strongpointID);
};

}
