// CopyRight Shaquille Etienne

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//TODO Remove once firing is moved 
	UPROPERTY(EditDefaultsOnly, Category = "Firing")//This makes it appear in the unreal BP under ther category "Firing"
	float LaunchSpeed = 4000.0;
		
	UPROPERTY(EditDefaultsOnly, Category = "Firing")//'EditDefaultsOnly' Makes it so that it can only be edited in the Blueprint
	float ReloadTimeInSeconds = 3; // Rather than for seprate instance. So each tank cant have different reload speeds
	
	UTankBarrel* Barrel = nullptr;//TODO Remove 

	double LastFireTime = 0;

};
