// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


class UTankBarrel; //forward Declaration
class UTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// TODO Add Set TurretReferences 
	
public:	
	void AimAt(FVector Hitlocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel * BarrelToSet);
	void SetTurretReference(UTurret * TurretToSet);
private :
	UTankBarrel * Barrel = nullptr;
	void MoveBarrelToward(FVector AimDirection);
	
	UTurret * Turret = nullptr;
	void RotateTurret(FVector AimDirection);
};
