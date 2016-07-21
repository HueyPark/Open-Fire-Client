// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameObject/GameObject.h"
#include "Type/Request.h"
#include "StrongPoint.generated.h"

class UStaticMeshComponent;
enum class Request : uint8;

UCLASS()
class OPENFIRE_API AStrongpoint : public AGameObject
{
	GENERATED_BODY()

protected:
	FString id;
	int32 level;
	ERequest request;

public:
	AStrongpoint();

	void Init(const FString id, const int32 level, const Request request);

	UFUNCTION(BlueprintImplementableEvent)
	void PostInit(const FString& id, const int32& level, const ERequest& request);

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);

protected:
	UFUNCTION(BlueprintCallable, Category = "AStrongpoint")
	FLinearColor _GetColor();
};
