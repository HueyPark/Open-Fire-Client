// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject/GameObject.h"
#include "StrongPoint.generated.h"

class UStaticMeshComponent;

UCLASS()
class OPENFIRE_API AStrongPoint : public AGameObject
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* staticMeshComponent;
	FString id;

public:
	AStrongPoint();

	void Initialize(const FString id);

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);
};
