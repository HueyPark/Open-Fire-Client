// Free to use

#pragma once

#include "Object.h"
#include "WorldGraph.generated.h"

class UStrongpointModel;
class URoadModel;

UCLASS()
class OPENFIRE_API UWorldGraph : public UObject
{
	GENERATED_BODY()

private:
	TArray<UStrongpointModel*> StrongPointModels;
	TArray<URoadModel*> RoadModels;

public:
	void Init();

	void OnUpdate();

	const TArray<UStrongpointModel*>& GetStrongPointModels();
};
