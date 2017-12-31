// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"








void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	{
		auto PlayerTank = GetPlayerTank();		

			if (!PlayerTank)
			{
				UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find PLAYER TANK"))
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AI Controller Find PLAYER TANK : %s"),*(PlayerTank->GetName())) 
			}
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//move towards the player

		// Aim at the player 
		
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//fire if ready
	}

	 
}




ATank * ATankAIController::GetAIControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerPawn) {	return nullptr;	}
	
	return Cast<ATank>(PlayerPawn);


}
