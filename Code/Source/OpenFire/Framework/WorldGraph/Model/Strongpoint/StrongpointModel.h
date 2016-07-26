// Free to use

#pragma once

#include "Object.h"
#include "StrongPointModel.generated.h"

UCLASS()
class OPENFIRE_API UStrongpointModel : public UObject
{
	GENERATED_BODY()

public:
	int32 Id;
	FVector Location;

public:
	void Init(int32 Id, const FVector Location);
};
