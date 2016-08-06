 // CopyRight Shaquille Etienne
#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
	//No need to protect points as added at construction
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));// This make its appear as inhertinace in the bp

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	//This reloads the tank 
	//FPlatformTime::Seconds() is more precise
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded) 
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



