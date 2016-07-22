// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"//Remeber to include tank 
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	ATank *GetControlledTank() const;

	virtual void BeginPlay() override;
	

};
