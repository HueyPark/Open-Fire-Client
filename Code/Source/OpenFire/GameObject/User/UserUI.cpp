// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenFire.h"
#include "UserUI.h"

#include "User.h"

void UUserUI::NativeConstruct()
{
	User = Cast<AUser>(GetOwningPlayerPawn());
}

void UUserUI::SpawnTree()
{
	User->SpawnTree();
}
