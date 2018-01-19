// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatUIWidget.h"
#include "TestCombatAction.h"
#include "CombatEngine.h"

void UCombatUIWidget::BeginMakeDecision(UGameCharacter* target)
{
	UE_LOG(LogTemp, Log, TEXT("%s is making decision"), *target->CharacterName);
	this->currentTarget = target;
	this->finishedDecision = false;
	ShowActionsPanel(target);
}

bool UCombatUIWidget::MakeDecision(float DeltaSeconds)
{
	return this->finishedDecision;
}

void UCombatUIWidget::AttackTarget(UGameCharacter* target)
{
	UE_LOG(LogTemp, Log, TEXT("%s decided to attack"), *currentTarget->CharacterName, *target->CharacterName);
	TestCombatAction* action = new TestCombatAction(target);
	this->currentTarget->combatAction = action;
	this->finishedDecision = true;
}

TArray<UGameCharacter*> UCombatUIWidget::GetCharacterTargets()
{
	if(this->currentTarget->isPlayer)
	{
		return this->currentTarget->combatInstance->enemyParty;
	}
	else
	{
		return this->currentTarget->combatInstance->playerParty;
	}
}