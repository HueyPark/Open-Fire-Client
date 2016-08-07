// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BuilderAI.generated.h"

UCLASS()
class OPENFIRE_API ABuilderAI : public AAIController
{
	GENERATED_BODY()

public:
	FName TargetKey;

private:
	UPROPERTY(transient)
	class UBlackboardComponent* BlackboardComp;

	UPROPERTY(transient)
	class UBehaviorTreeComponent* BehaviorTreeComp;

public:
	ABuilderAI();

	virtual void Possess(APawn* InPawn) override;
};
