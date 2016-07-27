// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject/GameObject.h"
#include "StrongPoint.generated.h"

class UResource;
class UStaticMeshComponent;
class UStrongpointModel;

UCLASS()
class OPENFIRE_API AStrongpoint : public AGameObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	const UStrongpointModel* Model;

public:
	AStrongpoint();

	void Init(const UStrongpointModel* Model);

	UFUNCTION(BlueprintImplementableEvent)
	void PostInit();

protected:
	UFUNCTION(BlueprintCallable, Category = "AStrongpoint")
	FLinearColor _GetColor();
};
