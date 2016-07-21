// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

//defining beginplay
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//protecting pointers 
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else{
		UE_LOG(LogTemp, Warning, TEXT("%s  begin play"),*(ControlledTank->GetName()));
	}
	

}

ATank* ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("Posssessing begin play"));
}
