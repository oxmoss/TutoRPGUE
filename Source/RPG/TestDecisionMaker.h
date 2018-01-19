// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IDecisionMaker.h"

class RPG_API TestDecisionMaker : public IDecisionMaker
{
public:
	virtual void BeginMakeDecision(UGameCharacter* character) override;
	virtual bool MakeDecision(float DeltaSeconds) override;
};

