// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CombatEngine.h"
#include "CombatUIWidget.h"
#include "RPGGameMode.generated.h"


/**
 * 
 */
UCLASS()
class RPG_API ARPGGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ARPGGameMode(const class FObjectInitializer& ObjectInitializer );
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Allow function to be executed in UE4 console
	UFUNCTION(exec, BlueprintCallable)
	void TestCombat();

	CombatEngine* currentCombatInstance;
	UPROPERTY()
	TArray<UGameCharacter*> enemyParty;

	//CombatUI widget. To dislpay at combat start.
	UPROPERTY()
	UCombatUIWidget* CombatUIInstance;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UCombatUIWidget> CombatUIClass;

	//GameOverUI widget
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> GameOverUIClass;


	//GameOverUI widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool debugEnabled;
};
