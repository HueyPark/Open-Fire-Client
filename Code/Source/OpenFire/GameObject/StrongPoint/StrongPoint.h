// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject/GameObject.h"
#include "StrongPoint.generated.h"

class UStaticMeshComponent;
enum class Request;

UCLASS()
class OPENFIRE_API AStrongpoint : public AGameObject
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* staticMeshComponent;
	FString id;
	int32 level;
	Request request;

public:
	AStrongpoint();

	void Initialize(const FString id, const int32 level, const Request request);

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);

private:
	FLinearColor _GetColor();
};
