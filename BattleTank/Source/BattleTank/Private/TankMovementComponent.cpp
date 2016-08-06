// CopyRight Shaquille Etienne

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet && RightTrackToSet)) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No reason to call super because we are replacing the functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();//Gets the x vector of the tanks 
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();//safe normal, gets you a normal vertor of of this move velocity with out changing it
	
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention); //
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;// The sine Function //We ge the z component to get a float 
	
	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);
														   
}

//This method doesnt requre anothr method to move back back the analog stick can give a negatibe number which will reverse the tank 
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	
	if (!ensure(LeftTrack && RightTrack)) { return; }
	/**
	* This gets the variables left track and right track and calls the setThrottle in the tank track class
	* which moves the tank 
	*/
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	
}


//This method is similar to the intendMoveForward we only need to add a minus to the throw on the right track to move it left or right 
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	/**
	* This gets the variables left track and right track and calls the setThrottle in the tank track class
	* which moves the tank
	*/
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

}