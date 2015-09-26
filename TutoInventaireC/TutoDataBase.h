// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TutoDataBase.generated.h"


USTRUCT()
struct FItem
{
	GENERATED_USTRUCT_BODY()

	//mettre vos variables et fonctions ici

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Nom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantite;

	FItem()
	{
		//mettre l'initialisation des variables ici
		ID = -1;
		Nom = "UNKNOWN";
		Quantite = 1;
	}
};


UCLASS()
class TUTOINVENTAIREC_API ATutoDataBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATutoDataBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Inventory of the player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TArray<FItem> ItemDataBase;
	
};
