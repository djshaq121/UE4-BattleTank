// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"



UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//Drive the tracks 
	DriveTrack();
	//Apply sideways force 
	ApplySidewaysForce();
	//Reset throttle or the throttle will keep on going 
	CurrentThrottle = 0;
	
}

void UTankTrack::ApplySidewaysForce()
{
	//work out the required acceleration this frame to correct
	//Calculate the sideways speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//Calculate and apply sideways (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;//two tracks
	TankRoot->AddForce(CorrectionForce);
}


//This is what moves the tank 
void UTankTrack::SetThrottle(float Throttle)
{
	//auto time = GetWorld()->GetTimeSeconds();
	//TODO clamp the the throttle value so player cant  over drive 

	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
	//When the move forwared and turn right is called at the same time we dont want it to exceed 1 or minus 1
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;//The forward vector is the direction that is straight in front of the actor, based on its root component
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());// Cast the root, 'Tank', to a PrimitiveComponent
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}