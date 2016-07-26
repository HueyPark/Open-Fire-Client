// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject/GameObject.h"
#include "StrongPoint.generated.h"

class UStaticMeshComponent;

UCLASS()
class OPENFIRE_API AStrongpoint : public AGameObject
{
	GENERATED_BODY()

protected:
	int32 Id;
	int32 Level;

public:
	AStrongpoint();

	void Init(const int32 Id, const int32 Level);

	UFUNCTION(BlueprintImplementableEvent)
	void PostInit(const int32& Id, const int32& Level);

protected:
	UFUNCTION(BlueprintCallable, Category = "AStrongpoint")
	FLinearColor _GetColor();
};
