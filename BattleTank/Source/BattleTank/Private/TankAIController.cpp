// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//protecting pointers 
	auto PlayerTank = GetControlledTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank %s"), *(PlayerTank->GetName()));
	}
}

//This gets the pawn from the tank class
ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("Posssessing begin play"));
}

ATank *ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController();
	if (!PlayerPawn) { return nullptr; }//Checks if there is a playerController if not then return a nullpointer
	return Cast<ATank>(PlayerPawn);
}