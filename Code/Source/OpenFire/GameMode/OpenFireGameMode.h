#pragma once

#include "GameFramework/GameMode.h"
#include "OpenFireGameMode.generated.h"

class UGameObjectManager;
class UWorldGraph;

UCLASS()
class OPENFIRE_API AOpenFireGameMode : public AGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UGameObjectManager* gameObjectManager;

private:
	UWorldGraph* WorldGraph;

public:
	AOpenFireGameMode();

public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void Tick(float DeltaSeconds) override;
};
