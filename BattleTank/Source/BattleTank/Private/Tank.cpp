// Fill out your copyright notice in the Description page of Project Settings.
#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "TankAimingComponent.h"//You will include this class if its used in the class
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Donkey: Tank C++ Construct "), *TankName)
	//No need to protect points as added at construction
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));// This make its appear as inhertinace in the bp

}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Donkey: Tank C++ Begin play "), *TankName)
	
}

void ATank::Fire()
{
	
	//This reloads the tank 
	//FPlatformTime::Seconds() is more precise
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded) 
	{
		//Spawn a projectile from the socket location
		//We return the projectile into a variable called 'projectile' than call the mtehod launchProjectile
		auto projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		//Calling launchProjectile
		projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}


}



