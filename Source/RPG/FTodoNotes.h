#pragma once

#include "Engine/DataTable.h"
#include "FTodoNotes.generated.h"

USTRUCT(BlueprintType)
struct FTodoNotes : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	//FTestCustomData() :SomeNumber(0), SomeString("") {}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Todo")
		int32 State;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Todo")
		int32 Importance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Todo")
		FString Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Todo")
		TArray<FString> Sidenote;
};