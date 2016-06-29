// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject//GameObject.h"
#include "StrongPointEdge.generated.h"

UCLASS()
class OPENFIRE_API AStrongPointEdge : public AGameObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStrongPointEdge();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
};
