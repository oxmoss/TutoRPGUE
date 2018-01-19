// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"

#include "IDecisionMaker.h"
#include "Blueprint/UserWidget.h"
#include "CombatUIWidget.generated.h"

UCLASS()
class RPG_API UCombatUIWidget : public UUserWidget, public IDecisionMaker
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	UGameCharacter* currentTarget;

protected:
	bool finishedDecision;

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
	void AddPlayerCharacterPanel(UGameCharacter* target);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
	void AddEnemyCharacterPanel(UGameCharacter* target);

	void BeginMakeDecision(UGameCharacter* target);
	bool MakeDecision(float DeltaSeconds);

	UFUNCTION(BlueprintCallable, Category = "Combat UI")
	TArray<UGameCharacter*> GetCharacterTargets();

	UFUNCTION(BlueprintCallable, Category = "Combat UI")
	void AttackTarget(UGameCharacter* target);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
	void ShowActionsPanel(UGameCharacter* target);
};