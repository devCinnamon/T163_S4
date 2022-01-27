// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lab1_MainCharacter.h"
#include "Animation/AnimInstance.h"
#include "Lab1_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LAB1_GASTELLO_API ULab1_AnimInstance : public UAnimInstance
{
	
public:
	GENERATED_BODY()
	
	virtual void NativeInitializeAnim();

	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
	void UpdateAnimationProperties();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	float movementSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	bool isInAir;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	bool isAccelerating;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	class APawn* OwningPawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	class ALab1_MainCharacter * MainCharacter;
};
