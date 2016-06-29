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
	UStaticMeshComponent* staticMeshComponent = nullptr;

	int32 strongPointID = -1;

public:
	AStrongPoint();

	void Initialize(int32 strongPointID);

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);
};
