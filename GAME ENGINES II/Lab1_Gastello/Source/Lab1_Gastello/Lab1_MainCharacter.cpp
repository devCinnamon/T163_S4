// Fill out your copyright notice in the Description page of Project Settings.


#include "Lab1_MainCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ALab1_MainCharacter::ALab1_MainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FollowSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("FollowSpringArm"));
	FollowSpringArm->SetupAttachment(RootComponent);
	FollowSpringArm->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(FollowSpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	FPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	FPSCamera->SetupAttachment(GetMesh(), "head");
	FPSCamera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ALab1_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void ALab1_MainCharacter::MoveForward( float value )
{
	FVector forward = GetActorForwardVector();
	AddMovementInput(forward, value);
}


void ALab1_MainCharacter::MoveRight( float value )
{
	FVector right = GetActorRightVector();
	AddMovementInput(right, value);
}


void ALab1_MainCharacter::ToggleCamera()
{

	if(FollowCamera->IsActive())
	{
		FPSCamera->SetActive(true);
		FollowCamera->SetActive(false);
	}
	else
	{
		FollowCamera->SetActive(true);
		FPSCamera->SetActive(false);
	}

}

// Called every frame
void ALab1_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALab1_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ALab1_MainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALab1_MainCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("ToggleCamera", IE_Pressed, this, &ALab1_MainCharacter::ToggleCamera);
}

