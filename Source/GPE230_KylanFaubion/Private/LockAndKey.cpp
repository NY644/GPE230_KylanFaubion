// Fill out your copyright notice in the Description page of Project Settings.

#include "LockAndKey.h"
#include "MazeCharacter.h"


ALockAndKey::ALockAndKey()
{
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
}

// Checks if the other actor in this trigger
// is a MazeCharacter.
// If it is, open the door
void ALockAndKey::CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// If the other actor is a maze character
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
	{
		OpenTheDoor();
	}
}

void ALockAndKey::OpenTheDoor()
{
	this->Destroy();
}