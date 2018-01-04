// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;


private:
	
	
	UPROPERTY(EditAnyWhere, Category = Firing)
	float LaunchSpeed = 5000.f;
	
	// Sets default values for this pawn's properties
	ATank();
	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void AimAt(FVector Hitlocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel * BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTurret * TurretToSet);
	
	
	
};
