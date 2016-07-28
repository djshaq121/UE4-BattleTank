// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	
	virtual void Tick(float DeltaSecond) override;

	virtual void BeginPlay() override;

	ATank *GetControlledTank() const;

	ATank *GetPlayerTank() const;

};
