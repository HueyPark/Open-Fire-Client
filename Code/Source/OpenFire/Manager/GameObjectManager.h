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

	TMap<FString, AStrongPoint*> strongpointMap;
	TMap<int32, ABuilding*> buildingMap;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

private:
	void SpawnStrongPoint(const FString id, const FVector location);
	void SpawnBuilding(int32 buildingID, int32 strongPointID, ObjectDataType type);

	void UpdateStrongPoints();
	void UpdateBuildings();
};
