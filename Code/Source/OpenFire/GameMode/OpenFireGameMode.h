#pragma once

#include "GameFramework/GameMode.h"
#include "OpenFireGameMode.generated.h"

class WorldGraph;

UCLASS()
class OPENFIRE_API AOpenFireGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	float accumulatedSeconds = 0.0f;

public:
	AOpenFireGameMode();

public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void Tick(float DeltaSeconds) override;
};
