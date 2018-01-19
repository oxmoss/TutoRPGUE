// Fill out your copyright notice in the Description page of Project Settings.

#include "RPGGameInstance.h"


void URPGGameInstance::Init()
{
	if(this->isInitialized) return;

	this->isInitialized = true;

	this->PartyMembers.Empty();

	// locate characters asset
	UDataTable* characters = Cast<UDataTable>(StaticLoadObject( UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/Ressources/DataTables/RPG_CharacterInfo.RPG_CharacterInfo'")) );
	if(characters == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Characters data table not found!" ) );
		return;
	}

	/*
	// locate character
	FCharacterInfo* row = characters->FindRow<FCharacterInfo>(TEXT("C1"), TEXT("LookupCharacterClass"));
	if(row == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Character ID 'C1' not found!") );
		return;
	}
	// add character to party
	this->PartyMembers.Add(UGameCharacter::CreateGameCharacter(row, this));
	//*/

	TArray<FName> RowNames = characters->GetRowNames();
	for(auto& name : RowNames)
	{
		FCharacterInfo* row = characters->FindRow<FCharacterInfo>(name, TEXT("LookupCharacterClass"));
		if(row == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("Character ID not found!"));
			return;
		}

		// add character to party
		this->PartyMembers.Add(UGameCharacter::CreateGameCharacter(row, this));
	}

}

void URPGGameInstance::PrepareReset()
{
	this->isInitialized = false;
}