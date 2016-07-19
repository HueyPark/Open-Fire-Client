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
	UStaticMeshComponent* staticMeshComponent;

	UPROPERTY(BlueprintReadOnly)
	FString id;

	UPROPERTY(BlueprintReadOnly)
	int32 level;

	UPROPERTY(BlueprintReadOnly)
	ERequest request;

public:
	AStrongpoint();

	void Init(const FString id, const int32 level, const Request request);

	UFUNCTION(BlueprintNativeEvent)
	void AfterInit();
	virtual void AfterInit_Implementation();

	UFUNCTION(Category = Default)
	void OnInputTouchBegin(ETouchIndex::Type fingerIndex, UPrimitiveComponent* touchedComponent);

private:
	FLinearColor _GetColor();
};
