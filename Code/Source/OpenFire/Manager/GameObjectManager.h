#pragma once

#include "Framework/Singleton.h"

class AStrongPoint;
class AGameObject;
class ABuilding;
enum class ObjectDataType;

class OPENFIRE_API GameObjectManager : public Singleton<GameObjectManager>
{
private:
	UWorld* world = nullptr;

	TMap<int32, AStrongPoint*> strongPointMap;
	TMap<int32, ABuilding*> buildingMap;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

private:
	void SpawnStrongPoint(int32 nodeID, FVector location);
	void SpawnBuilding(int32 buildingID, int32 strongPointID, ObjectDataType type);

	void UpdateStrongPoints();
	void UpdateBuildings();
};
