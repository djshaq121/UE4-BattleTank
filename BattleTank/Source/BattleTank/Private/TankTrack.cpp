// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


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
