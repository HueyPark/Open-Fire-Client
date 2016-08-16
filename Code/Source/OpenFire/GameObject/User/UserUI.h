// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UserUI.generated.h"

class AUser;

UCLASS()
class OPENFIRE_API UUserUI : public UUserWidget
{
	GENERATED_BODY()

private:
	AUser* User;

public:
	virtual void NativeConstruct() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "UserUI")
	void SpawnTree();
};
