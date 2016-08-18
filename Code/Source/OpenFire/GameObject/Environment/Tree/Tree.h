// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject/Environment/Environment.h"
#include "Tree.generated.h"

UCLASS()
class OPENFIRE_API ATree : public AEnvironment
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	float Size;

public:
	ATree();

	virtual void Tick(float DeltaSeconds) override;
};
