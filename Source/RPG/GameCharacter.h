// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FCharacterInfo.h"
#include "FCharacterClassInfo.h"
#include "FEnemyInfo.h"
#include "ICombatAction.h"
#include "IDecisionMaker.h"
#include "GameCharacter.generated.h"

class CombatEngine;
class ICombatAction;
class IDecisionMaker;

UCLASS(BlueprintType)
class RPG_API UGameCharacter : public UObject
{
	GENERATED_BODY()
public:
	FCharacterClassInfo* ClassInfo;
	CombatEngine* combatInstance;
	ICombatAction* combatAction;
	IDecisionMaker* decisionMaker;
	bool isPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		FString CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 MHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 MMP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 MP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 ATK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 DEF;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 LUCK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
		int32 Gold;

	static UGameCharacter* CreateGameCharacter(FCharacterInfo* characterInfo, UObject* outer);
	static UGameCharacter* CreateGameCharacter(FEnemyInfo* enemyInfo, UObject* outer);

	void BeginDestroy() override;
protected:
	float testDelayTimer;
public:
	void BeginMakeDecision();
	bool MakeDecision(float DeltaSeconds);
	void BeginExecuteAction();
	bool ExecuteAction(float DeltaSeconds);
	UGameCharacter* SelectTarget();
};