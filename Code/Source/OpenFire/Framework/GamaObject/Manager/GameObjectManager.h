// Free to use

#pragma once

#include "Object.h"
#include "GameObjectManager.generated.h"

class AStrongpoint;
enum class Request;

UCLASS()
class OPENFIRE_API UGameObjectManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AStrongpoint> CLASS_Strongpoint;

private:
	UWorld* world;

	TMap<FString, AStrongpoint*> strongpointMap;

public:
	void Init(UWorld* world);
	void OnUpdate();

private:
	void _SpawnStrongPoint(const FString id, const FVector location, const int32 level, const Request request);

	void _UpdateStrongPoints();
};
