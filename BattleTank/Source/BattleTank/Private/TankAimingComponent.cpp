// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//auto OurTankName = GetOwner()->GetName();//Gets the name of the tank 
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();//we created a barrel virable, we get the barrel location yousing the get, IT returns a FVector so we use a ToString to change it to a string
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *OurTankName, *HitLocation.ToString(), *BarrelLocation);
	
	if (!Barrel) { return; }
	
	
		FVector OutLaunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));//This gets the socket location



	//Calculate the OutLaunchVelocity
		if (UGameplayStatics::SuggestProjectileVelocity(
			this, 
			OutLaunchVelocity, 
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace ))
		{
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			UE_LOG(LogTemp, Warning, TEXT("Aiming at at %s"), *AimDirection.ToString());
		}
		
	
}
