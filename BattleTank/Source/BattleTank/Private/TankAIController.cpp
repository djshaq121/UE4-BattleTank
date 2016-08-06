// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"//
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());//This cast it from a pawn to a tank
	auto AITank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		//Move the tank towards the player
		//3000cm = 30m
		MoveToActor(PlayerTank, AcceptanceRadius);
		//Aim at the player 
		AITank->AimAt(PlayerTank->GetActorLocation());

		//Fire if ready
		AITank->Fire();//TODO Limit the firing rate
	}
	
}




