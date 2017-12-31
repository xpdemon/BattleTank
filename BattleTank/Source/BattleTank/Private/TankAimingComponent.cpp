// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();


	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

 void UTankAimingComponent::AimAt(FVector Hitlocation,float LaunchSpeed)
{
	 if (!Barrel) { return; }

	 FVector OutLaunchVelocity;
	 FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	 //Calculate the OutLaunchVelocity
	 if (UGameplayStatics::SuggestProjectileVelocity(
		 this,
		 OutLaunchVelocity,
		 StartLocation,
		 Hitlocation,
		 LaunchSpeed,
		 false,
		 0.f,
		 0.f,
		 ESuggestProjVelocityTraceOption::DoNotTrace))
	 {
		 auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		 UE_LOG(LogTemp, Warning, TEXT("aiming at at %s"),* AimDirection.ToString());
	 }

	
}

 void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
 {
	 Barrel = BarrelToSet;
 }
