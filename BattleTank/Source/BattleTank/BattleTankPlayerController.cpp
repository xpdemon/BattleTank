// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankPlayerController.h"



void ABattleTankPlayerController::BeginPlay()
{
	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not Possessing a TANK"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possessing : %s"), *(ControlledTank->GetName()));
	}
}

ATank *ABattleTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


