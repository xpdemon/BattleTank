// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	void Elevate(float RelativeSpeed);

private :

	UPROPERTY(EditAnywhere, Category = Elevation)
		float MaxDegressPerSecond =5.0f;
	
	UPROPERTY(EditAnywhere, Category = Elevation)
		float MaxElevation = 30.0f;
	
	UPROPERTY(EditAnywhere, Category = Elevation)
		float MinElevation = 0.0f;	
};

