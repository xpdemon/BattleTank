// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Turret.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

 void UTankAimingComponent::AimAt(FVector Hitlocation,float LaunchSpeed)
{
	 if (!Barrel) { return; }
	 if (!Turret) { return; }

	 FVector OutLaunchVelocity;
	 FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	 bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this,OutLaunchVelocity,StartLocation,Hitlocation,LaunchSpeed,false,0.f,0.f,ESuggestProjVelocityTraceOption::DoNotTrace);
	 //Calculate the OutLaunchVelocity

	 if (bHaveAimSolution)
	 {
		 auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		 auto TankName = GetOwner()->GetName();
		 MoveBarrelToward(AimDirection);
		 RotateTurret(AimDirection);
		 auto Time = GetWorld()->GetTimeSeconds(); 
		 
	 }
	
}

 void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
 {
	 Barrel = BarrelToSet;
	 
 }

 void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
 {
	 auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	 auto AimAsRotator = AimDirection.Rotation();
	 auto DeltaRotator = AimAsRotator - BarrelRotator;	
	 
	 Barrel->Elevate(DeltaRotator.Pitch);	 
 }

 void UTankAimingComponent::SetTurretReference(UTurret * TurretToSet)
 {
	 Turret = TurretToSet;
 }

  void UTankAimingComponent::RotateTurret(FVector AimDirection)
 {
	 auto TurretRotator = Turret->GetForwardVector().Rotation();
	 auto AimAsRotator = AimDirection.Rotation();
	 auto DeltaRotator = AimAsRotator - TurretRotator;

	 Turret->TurretRotation(DeltaRotator.Yaw);

 }