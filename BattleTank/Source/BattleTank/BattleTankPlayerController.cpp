// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankPlayerController.h"





	


// At the Start 
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



// call Every Frame


void ABattleTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AIMTowardCrossHair();
	

}

void ABattleTankPlayerController::AIMTowardCrossHair()
{
	if (!GetControlledTank()) { return; }

	
	FVector Hitlocation;
	if (GetSightRayHitLocation(Hitlocation))
	{
		

			//TODO tell controlles to aim at this point
	}
	
}

//Get World location of line trace Through CrossHair , //if it hit the landscape return true
bool ABattleTankPlayerController::GetSightRayHitLocation(FVector& Hitlocation) const
{
	//Find the crosshair position
	int32 ViewPortsizeX, ViewPortsizeY;
	GetViewportSize(ViewPortsizeX, ViewPortsizeY);
	FVector LookDirection;
	auto ScreenLocation = FVector2D((ViewPortsizeX * CrossHairXLocation), (ViewPortsizeY*CrossHairYLocation));
	
	
	//"De-project " the screen position to the crosshair to a world direction 
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		
		UE_LOG(LogTemp, Warning, TEXT(" LookDirection : %s"), *LookDirection.ToString());

	}
	//Line -Trace along tha look direction , and see what we hit 

	return false;
}

bool ABattleTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // For Discarding	
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}




ATank *ABattleTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}




