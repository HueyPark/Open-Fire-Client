// Free to use

#pragma once

#include "Object.h"
#include "Resource.generated.h"

UCLASS()
class OPENFIRE_API UResource : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	int32 Id;

	UPROPERTY(BlueprintReadOnly)
	int32 Value;

public:
	void Init(int32 Id, int32 Value);
};
