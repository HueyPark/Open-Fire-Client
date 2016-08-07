// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "../../Builder/BuilderAI.h"
#include "BTTask_MoveToLocation.h"

EBTNodeResult::Type UBTTask_MoveToLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABuilderAI* BuilderAI = Cast<ABuilderAI>(OwnerComp.GetAIOwner());

	FVector Location = OwnerComp.GetBlackboardComponent()->GetValueAsVector(BuilderAI->TargetKey);
	BuilderAI->MoveToLocation(Location, 5.0f);
	return EBTNodeResult::Succeeded;
}
