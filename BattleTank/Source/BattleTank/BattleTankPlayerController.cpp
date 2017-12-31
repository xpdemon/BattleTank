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
		GetControlledTank()->AimAt(Hitlocation);
		
		
		
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
		//Line -Trace along tha look direction , and see what we hit 
		GetLookVectorHitLocation(LookDirection, Hitlocation);

	}
	 

	return true;
}

bool ABattleTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // For Discarding	
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ABattleTankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& Hitlocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection* LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		Hitlocation =  HitResult.Location;
		return true;
	}
	Hitlocation = FVector(0);
	return false;
}




ATank *ABattleTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}




