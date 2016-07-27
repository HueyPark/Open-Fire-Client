// Free to use

#pragma once

#include "Object.h"
#include "GameObjectManager.generated.h"

class AStrongpoint;
class UStrongpointModel;
class UWorldGraph;
enum class Request : uint8;

UCLASS()
class OPENFIRE_API UGameObjectManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AStrongpoint> CLASS_Strongpoint;

private:
	UWorld* world;
	UWorldGraph* WorldGraph;

	TMap<int32, AStrongpoint*> StrongPointMap;

public:
	void Init(UWorld* world, UWorldGraph* WorldGraph);
	void OnUpdate();

private:
	void _SpawnStrongPoint(const UStrongpointModel* Model);

	void _UpdateStrongPoints();
};
