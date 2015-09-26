#pragma once

#include "Data.generated.h"


USTRUCT()
struct FRequirement
{
	GENERATED_USTRUCT_BODY()

	//mettre vos variables et fonctions ici

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirement")
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirement")
	int32 Quantite;

	FRequirement()
	{
		//mettre l'initialisation des variables ici
		ID = -1;
		Quantite = 1;
	}
};

USTRUCT()
struct FCraft
{
	GENERATED_USTRUCT_BODY()

	//mettre vos variables et fonctions ici

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Craft")
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Craft")
	int32 Quantite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Craft")
	TArray<FRequirement> Requirement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Craft")
	FString Nom;

	FCraft()
	{
		//mettre l'initialisation des variables ici
		ID = -1;
		Quantite = 0;
		Nom = "UNKNOWN";
	}
};