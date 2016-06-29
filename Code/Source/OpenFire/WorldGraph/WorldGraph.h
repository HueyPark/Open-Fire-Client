#pragma once

#include "Framework/Singleton.h"
#include "WorldGraph/StrongPointData.h"
#include "WorldGraph/ObjectData/BuildingData.h"

class MissionValues;
enum class ObjectDataType;

class OPENFIRE_API WorldGraph : public Singleton<WorldGraph>
{
private:
	UWorld* world = nullptr;

	TArray<StrongPointData> strongPointDatas;
	TArray<BuildingData> buildingDatas;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

	const StrongPointData* GetStrongPointData(int32 nodeID);

	const TArray<StrongPointData>& GetStrongPointDatas();
	const TArray<BuildingData>& GetBuildingDatas();

	void InsertUpdateStrongPointData(int32 id, FVector location);
	void InsertUpdateBuildingData(int32 buildingID, int32 strongpointID);
};
