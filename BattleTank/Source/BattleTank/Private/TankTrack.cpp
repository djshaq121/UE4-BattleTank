// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//Calculate the sideways speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//work out the required acceleration this frame to correct
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

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;//The forward vector is the direction that is straight in front of the actor, based on its root component
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());// Cast the root, 'Tank', to a PrimitiveComponent
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
