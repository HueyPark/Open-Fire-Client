#pragma once

#include "Framework/Singleton.h"

class AStrongpoint;
class AGameObject;
class ABuilding;
enum class ObjectDataType;
enum class Request;

class OPENFIRE_API GameObjectManager : public Singleton<GameObjectManager>
{
private:
	UWorld* world;

	TMap<FString, AStrongpoint*> strongpointMap;
	TMap<int32, ABuilding*> buildingMap;

public:
	void Initialize(UWorld* world);

	void OnUpdate();

private:
	void SpawnStrongPoint(const FString id, const FVector location, const int32 level, const Request request);
	void SpawnBuilding(int32 buildingID, int32 strongPointID, ObjectDataType type);

	void UpdateStrongPoints();
	void UpdateBuildings();
};
