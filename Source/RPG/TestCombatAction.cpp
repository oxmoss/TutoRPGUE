// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCombatAction.h"
#include "RPG.h"

TestCombatAction::TestCombatAction(UGameCharacter* target)
{
	this->target = target;
}

void TestCombatAction::BeginExecuteAction(UGameCharacter* character)
{
	this->character = character;

	this->delayTimer = 0.25f;
}

bool TestCombatAction::ExecuteAction(float DeltaSeconds)
{	
	this->delayTimer -= DeltaSeconds;

	if(this->delayTimer <= 0.0f)
	{
		// target is dead, select another target
		if(this->target->HP <= 0)
		{
			this->target = this->character->SelectTarget();
		}

		// no target, just return
		if(this->target == nullptr)
		{
			return true;
		}

		UE_LOG(LogTemp, Log, TEXT("%s attacks %s"), *character->CharacterName, *target->CharacterName);
		target->HP -= 10;

		return true;
	}
	return false;
}
