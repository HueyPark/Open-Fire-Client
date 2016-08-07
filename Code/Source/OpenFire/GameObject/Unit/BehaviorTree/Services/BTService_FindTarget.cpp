// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "../../Builder/BuilderAI.h"
#include "BTService_FindTarget.h"

UBTService_FindTarget::UBTService_FindTarget()
{
	bCreateNodeInstance = true;
}

void UBTService_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ABuilderAI* BuilderAI = Cast<ABuilderAI>(OwnerComp.GetAIOwner());

	if (BuilderAI)
	{
		APawn* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();

		OwnerComp.GetBlackboardComponent()->SetValueAsObject(BuilderAI->TargetKey, Pawn);
		UE_LOG(LogTemp, Warning, TEXT("Target Find"));
	}
}
