// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();//This cast it from a pawn to a tank
	auto AITank = GetPawn();

	if (!ensure(PlayerTank && AITank)) { return; }
	
	//Move the tank towards the player
	//3000cm = 30m
	MoveToActor(PlayerTank, AcceptanceRadius);
	//Aim at the player 
	auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	AimingComponent->Fire();
	
	
}




