// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "TutoDataBase.h"
#include "TutoItem.h"
#include "Data.h"
#include "TutoJoueur.generated.h"

UCLASS()
class TUTOINVENTAIREC_API ATutoJoueur : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATutoJoueur();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Inventory as an array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TArray<FItem> Inventaire;

	// Inventory as an array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 NombreMaxItem;

	// Open or Close the inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool InventaireVisuel;

	// The item to pickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	AActor* ItemToPickUp;

	// Return the Index of the actual craft
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 IndexCraft;

	// The Array of craft
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TArray<FCraft> Craft;

	//Move the player forward and backward
	UFUNCTION(BlueprintCallable, Category = Deplacment)
	void Avant(float value);

	//Move the player left and right
	UFUNCTION(BlueprintCallable, Category = Deplacment)
	void Droite(float value);

	// Change the inventory state
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void ChangeInventoryState();

	// Return the Number of Item from a specific ID
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	int32 GetNumberFromID(int32 TheID);
	
	// Return the Index of Item in the Inventory from a specific ID
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	int32 GetItemIndexWithID(int32 TheID);

	// Add an Item in the inventory with the specific ID
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void AddItemWithID(int32 TheID);

	// Remove an Item in the inventory with the specific ID
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void RemoveItemWithID(int32 TheID);

	// Remove an Item in the inventory with the specific ID and Number
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void RemoveItemWithIDAndNumber(int32 TheID, int32 TheNumber);

	// Craft the selected craftItem with the specific ID
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void CraftItem(int32 TheIndex);

	// TEST : Test the adding of an object
	UFUNCTION()
	void AjoutObjet();

	// TEST : Test the removing of an object
	UFUNCTION()
	void SuppressionObjet();

	//handles use
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void OnUse();

	// Go UP in the crafting list
	UFUNCTION()
	void MonteCraft();

	// Go DOWN in the crafting list
	UFUNCTION()
	void BaisseCraft();

	// Check if we have all the Item to craft the selected Item
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	bool GetEnoughItem(int32 TheIndex);
	
};
