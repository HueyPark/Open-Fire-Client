// Free to use

#pragma once

#include "Object.h"
#include "GameObjectManager.generated.h"

class AStrongpoint;
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

	TMap<FString, AStrongpoint*> strongpointMap;

public:
	void Init(UWorld* world, UWorldGraph* WorldGraph);
	void OnUpdate();

private:
	void _SpawnStrongPoint(const FString id, const FVector location, const int32 level, const Request request);

	void _UpdateStrongPoints();
};
