// Fill out your copyright notice in the Description page of Project Settings.

#include "RPGGameMode.h"

#include "RPGPlayerController.h"
#include "RPGCharacter.h"
#include "RPGGameInstance.h"
#include "Kismet/GameplayStatics.h"

ARPGGameMode::ARPGGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = ARPGPlayerController::StaticClass();
	DefaultPawnClass = ARPGCharacter::StaticClass();

	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

void ARPGGameMode::BeginPlay()
{
	Cast<URPGGameInstance>(GetGameInstance())->Init();
}

void ARPGGameMode::Tick(float DeltaTime)
{
	if(this->currentCombatInstance != nullptr)
	{
		bool combatOver = this->currentCombatInstance->Tick(DeltaTime);
		if(combatOver)
		{
			//END OF COMBAT
			if(this->currentCombatInstance->phase == CombatPhase::CPHASE_GameOver)
			{
				UE_LOG(LogTemp, Log, TEXT("Player loses combat, game over" ) );
				Cast<URPGGameInstance>(GetGameInstance())->PrepareReset();
				UUserWidget* GameOverUIInstance = CreateWidget<UUserWidget>(GetGameInstance(), this->GameOverUIClass);
				GameOverUIInstance->AddToViewport();
			}

			else if(this->currentCombatInstance->phase == CombatPhase::CPHASE_Victory)
			{
				UE_LOG(LogTemp, Log, TEXT("Player wins combat"));
				URPGGameInstance* gameInstance = Cast<URPGGameInstance>(GetGameInstance());
				gameInstance->Gold += this->currentCombatInstance->GoldTotal;
			}
			
			// enable back player actor
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(true);

			//Free the UI decision maker for the player party
			for(int i = 0; i < this->currentCombatInstance->playerParty.Num(); i++)
			{
				this->currentCombatInstance->playerParty[i]->decisionMaker = nullptr;//nullptr only, UE4 will Garbage collect the widget.
			}
			//Free the combat instance
			delete(this->currentCombatInstance);
			this->currentCombatInstance = nullptr;
			this->enemyParty.Empty();
			this->CombatUIInstance->RemoveFromViewport();
			this->CombatUIInstance = nullptr;
		}
	}
}

void ARPGGameMode::TestCombat()
{

	UE_LOG(LogTemp, Error, TEXT("breakpoint1."));
	// locate enemies asset
	UDataTable* enemyTable = Cast<UDataTable>(StaticLoadObject( UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/Ressources/DataTables/RPG_EnemyInfo.RPG_EnemyInfo'" ) ) );
	if(enemyTable == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemies data table not found!" ));
		return;
	}

	// locate enemy
	FEnemyInfo* row = enemyTable->FindRow<FEnemyInfo>(TEXT("E1"), TEXT("LookupEnemyInfo"));
	if(row == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemy ID 'E1' not found!"));
		return;
	}

	// disable player actor
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(false);

	// add character to enemy party
	UGameCharacter* enemy = UGameCharacter::CreateGameCharacter( row, this);
	this->enemyParty.Add(enemy);

	//Add a second enemy
	enemy = UGameCharacter::CreateGameCharacter(row, this);
	this->enemyParty.Add(enemy);

	URPGGameInstance* gameInstance = Cast<URPGGameInstance>( GetGameInstance());
	this->currentCombatInstance = new CombatEngine(gameInstance->PartyMembers, this->enemyParty);

	//Start the Combat UI at the start of a fight
	if(this->CombatUIInstance == nullptr)
	{

		UE_LOG(LogTemp, Log, TEXT("Spawning Combat UI widget"));
		this->CombatUIInstance = CreateWidget<UCombatUIWidget>(GetGameInstance(), this->CombatUIClass);
		this->CombatUIInstance->AddToViewport();
		for(int i = 0; i < gameInstance->PartyMembers.Num(); i++)
		{
			this->CombatUIInstance->AddPlayerCharacterPanel(gameInstance->PartyMembers[i]);
			gameInstance->PartyMembers[i]->decisionMaker = this->CombatUIInstance;
		}
		for(int i = 0; i < this->enemyParty.Num(); i++)
			this->CombatUIInstance->AddEnemyCharacterPanel(this->enemyParty[i]);
	}

	UE_LOG(LogTemp, Log, TEXT("Combat started"));
}