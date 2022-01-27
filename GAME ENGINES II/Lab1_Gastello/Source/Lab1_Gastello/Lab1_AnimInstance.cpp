// Fill out your copyright notice in the Description page of Project Settings.


#include "Lab1_AnimInstance.h"

#include "Lab1_MainCharacter.h"
#include "GameFramework/Pawn.h"

#include "GameFramework/CharacterMovementComponent.h"

void ULab1_AnimInstance::NativeInitializeAnim()
{
	Super::NativeInitializeAnimation();

	if(OwningPawn == nullptr)
	{
		OwningPawn = TryGetPawnOwner();
		if ( OwningPawn )
		{
			MainCharacter = Cast<ALab1_MainCharacter>(OwningPawn);
		}
	}
}

void ULab1_AnimInstance::UpdateAnimationProperties()
{
	if (OwningPawn == nullptr)
	{
		OwningPawn = TryGetPawnOwner();
	}
	if ( OwningPawn )
	{
		FVector speed = OwningPawn->GetVelocity();
		FVector lateralSpeed = FVector(speed.X, speed.Y, 0);

		movementSpeed = lateralSpeed.Size();

		isInAir = OwningPawn->GetMovementComponent()->IsFalling();
		if ( MainCharacter == nullptr )
		{
			MainCharacter = Cast<ALab1_MainCharacter>(OwningPawn);
		}
		if ( MainCharacter )
		{
			if ( MainCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0 )
			{
				isAccelerating = true;
			}
			else
			{
				isAccelerating = false;
			}
		}
	}
}
