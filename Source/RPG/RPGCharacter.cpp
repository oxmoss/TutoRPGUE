// Fill out your copyright notice in the Description page of Project Settings.

#include "RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

ARPGCharacter::ARPGCharacter(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 0.0f, 540.0f);
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}

void ARPGCharacter::MoveVertical(float Value)
{
	if(Controller != NULL && Value != 0.0f)
	{
		const FVector moveDir = FVector(1, 0, 0);
		AddMovementInput(moveDir, Value);
	}
}
void ARPGCharacter::MoveHorizontal(float Value)
{
	if(Controller != NULL && Value != 0.0f)
	{
		const FVector moveDir = FVector(0, 1, 0);
		AddMovementInput(moveDir, Value);
	}
}