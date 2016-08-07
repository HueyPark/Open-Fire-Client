// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Builder.h"
#include "BuilderAI.h"

ABuilderAI::ABuilderAI()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
}

void ABuilderAI::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	ABuilder* Builder = Cast<ABuilder>(InPawn);
	if (Builder && Builder->BehaviorTree)
	{
		BlackboardComp->InitializeBlackboard(*Builder->BehaviorTree->BlackboardAsset);

		TargetKey = TEXT("Target");
		TargetKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorTreeComp->StartTree(*Builder->BehaviorTree);
	}
}
