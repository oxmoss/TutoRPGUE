// Fill out your copyright notice in the Description page of Project Settings.

#include "TestDecisionMaker.h"
#include "RPG.h"
#include "TestCombatAction.h"

void TestDecisionMaker::BeginMakeDecision(UGameCharacter* character)
{
	//Lancer l'UI qui va demander l'action
	// pick a target
	UGameCharacter* target = character->SelectTarget();
	character->combatAction = new TestCombatAction(target);
}

bool TestDecisionMaker::MakeDecision(float DeltaSeconds)
{
	//Gerer l'UI, jq la decision
	return true;
}