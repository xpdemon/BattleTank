// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BattleTankPlayerController.generated.h"

class ATank;



UCLASS()
class BATTLETANK_API ABattleTankPlayerController : public APlayerController
{
	GENERATED_BODY()

public :

	ATank * GetControlledTank() const;	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:

	// start the tank moving the barrel so that a shot would hit where the crossHair intersects the world
	void AIMTowardCrossHair();
	bool GetSightRayHitLocation(FVector& Hitlocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirecton, FVector& Hitlocation) const;

	
	
};
