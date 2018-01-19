// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ICombatAction.h"

class TestCombatAction : public ICombatAction
{
protected:
	float delayTimer;
	UGameCharacter* character;
	UGameCharacter* target;
public:
	TestCombatAction(UGameCharacter* target);
	virtual void BeginExecuteAction(UGameCharacter* character) override;
	virtual bool ExecuteAction(float DeltaSeconds) override;
};