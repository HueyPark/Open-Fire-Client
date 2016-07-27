// Free to use

#pragma once

#include "Object.h"
#include "StrongPointModel.generated.h"

class UResource;

UCLASS()
class OPENFIRE_API UStrongpointModel : public UObject
{
	GENERATED_BODY()

public:
	int32 Id;

	int32 Level;

	FVector Location;

	UPROPERTY(BlueprintReadOnly)
	TArray<UResource*> Resources;

public:
	void Init(int32 Id, const FVector Location);
};
