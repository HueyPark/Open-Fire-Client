// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "../../Builder/BuilderAI.h"
#include "BTService_FindRandomLocation.h"

void UBTService_FindRandomLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ABuilderAI* BuilderAI = Cast<ABuilderAI>(OwnerComp.GetAIOwner());

	if (BuilderAI)
	{
		FNavLocation NavLocation = GetWorld()->GetNavigationSystem()->GetMainNavData()->GetRandomPoint();

		OwnerComp.GetBlackboardComponent()->SetValueAsVector(BuilderAI->TargetKey, NavLocation.Location);
	}
}
