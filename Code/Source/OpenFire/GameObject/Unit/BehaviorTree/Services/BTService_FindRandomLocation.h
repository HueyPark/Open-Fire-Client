// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTService.h"
#include "BTService_FindRandomLocation.generated.h"

UCLASS()
class OPENFIRE_API UBTService_FindRandomLocation : public UBTService
{
	GENERATED_BODY()

public:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override {}

	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override {}
};
