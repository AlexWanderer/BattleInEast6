// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleInEast6GameMode.h"
#include "BattleInEast6Character.h"
#include "UObject/ConstructorHelpers.h"

ABattleInEast6GameMode::ABattleInEast6GameMode() 
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/Blueprint/Pawn/BP_Character'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}



