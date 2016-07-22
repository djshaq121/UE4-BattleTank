// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//protecting pointers 
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possing: %s"), *(ControlledTank->GetName()));
	}
}

//This gets the pawn from the tank class
ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("Posssessing begin play"));
}
