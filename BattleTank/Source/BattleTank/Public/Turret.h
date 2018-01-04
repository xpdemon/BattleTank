// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void TurretRotation(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere,Category = Rotation)
		float MaxTurretRotation = 180;

	UPROPERTY(EditAnywhere, Category = Rotation)
		float MinTurretRotation = -180;


	UPROPERTY(EditAnywhere, Category = Rotation)
		float MaxDegressPerSecond = 25.0f;



	
	
};
