// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "../../Builder/BuilderAI.h"
#include "BTTask_MoveToTarget.h"

EBTNodeResult::Type UBTTask_MoveToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABuilderAI* BuilderAI = Cast<ABuilderAI>(OwnerComp.GetAIOwner());

	AActor* Target = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(BuilderAI->TargetKeyID));
	if (Target)
	{
		BuilderAI->MoveToActor(Target, 5.0f);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
