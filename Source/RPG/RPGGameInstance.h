// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameCharacter.h"
#include "RPGGameInstance.generated.h"


UCLASS()
class RPG_API URPGGameInstance : public UGameInstance
{
	GENERATED_BODY()
	//URPGGameInstance(const class FObjectInitializer& ObjectInitializer);
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Data" )
	TArray<UGameCharacter*> PartyMembers;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Data")
		bool TalkShop;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Data")
		bool MenuActive;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Data")
		int32 Gold;

protected:
	bool isInitialized;
public:
	void Init();
	void PrepareReset();
};