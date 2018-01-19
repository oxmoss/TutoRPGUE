// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyNewActor.generated.h"

class UDataTable;

UCLASS()
class RPG_API AMyNewActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My New Actor")
	UDataTable* DataTable;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My New Actor")
	FName rowName;

	// Sets default values for this actor's properties
	AMyNewActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
