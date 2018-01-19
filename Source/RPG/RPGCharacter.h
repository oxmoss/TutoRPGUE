// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ControllableCharacter.h"
#include "RPGCharacter.generated.h"

UCLASS()
class RPG_API ARPGCharacter : public ACharacter, public IControllableCharacter
{
	GENERATED_BODY()

	// Sets default values for this character's properties
	ARPGCharacter(const class FObjectInitializer& ObjectInitializer);
public:
	virtual void MoveVertical(float Value);
	
	virtual void MoveHorizontal(float Value);
	
};
