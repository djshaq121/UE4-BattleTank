// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;//This stops if from flying off when its construst it but only when we fire it 
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LaunchProjectile(float speed)
{
	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f Projectile fires Fires: %f "), time, speed);
	
	//This sets the speed of the projectile in the direction of the barrel
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	ProjectileMovement->Activate();
}