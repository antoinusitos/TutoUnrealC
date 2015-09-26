// Fill out your copyright notice in the Description page of Project Settings.

#include "TutoInventaireC.h"
#include "TutoJoueur.h"


// Sets default values
ATutoJoueur::ATutoJoueur()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NombreMaxItem = 5;

	FCraft ACraft;
	FRequirement require;

	ACraft.ID = 0;
	ACraft.Quantite = 0;
	ACraft.Nom = "Kit Soin";
	require.ID = 0;
	require.Quantite = 1;
	ACraft.Requirement.Add(require);
	require.ID = 2;
	require.Quantite = 1;
	ACraft.Requirement.Add(require);

	Craft.Add(ACraft);

	ACraft.Requirement.Empty();

	ACraft.ID = 1;
	ACraft.Quantite = 0;
	ACraft.Nom = "Couteau";
	require.ID = 4;
	require.Quantite = 1;
	ACraft.Requirement.Add(require);
	require.ID = 5;
	require.Quantite = 1;
	ACraft.Requirement.Add(require);
	require.ID = 1;
	require.Quantite = 1;
	ACraft.Requirement.Add(require);

	Craft.Add(ACraft);

	ACraft.Requirement.Empty();

	ACraft.ID = 2;
	ACraft.Quantite = 0;
	ACraft.Nom = "Crochetage";
	require.ID = 1;
	require.Quantite = 2;
	ACraft.Requirement.Add(require);

	Craft.Add(ACraft);

	ACraft.Requirement.Empty();

	ACraft.ID = 3;
	ACraft.Quantite = 0;
	ACraft.Nom = "Molotov";
	require.ID = 2;
	require.Quantite = 1;
	ACraft.Requirement.Add(require);
	require.ID = 3;
	require.Quantite = 1;
	ACraft.Requirement.Add(require);

	Craft.Add(ACraft);

	ACraft.Requirement.Empty();

	ACraft.ID = 4;
	ACraft.Quantite = 0;
	ACraft.Nom = "Bandage";
	require.ID = 3;
	require.Quantite = 2;
	ACraft.Requirement.Add(require);

	Craft.Add(ACraft);
}

// Called when the game starts or when spawned
void ATutoJoueur::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutoJoueur::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATutoJoueur::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("AjoutObjet", IE_Pressed, this, &ATutoJoueur::AjoutObjet);
	InputComponent->BindAction("SuppressionObjet", IE_Pressed, this, &ATutoJoueur::SuppressionObjet);
	InputComponent->BindAction("Inventaire", IE_Pressed, this, &ATutoJoueur::ChangeInventoryState);
	InputComponent->BindAction("Action", IE_Pressed, this, &ATutoJoueur::OnUse);
	InputComponent->BindAction("MonterCraft", IE_Pressed, this, &ATutoJoueur::MonteCraft);
	InputComponent->BindAction("BaisserCraft", IE_Pressed, this, &ATutoJoueur::BaisseCraft);

	InputComponent->BindAxis("Avant", this, &ATutoJoueur::Avant);
	InputComponent->BindAxis("Droite", this, &ATutoJoueur::Droite);
	InputComponent->BindAxis("Tourner", this, &ATutoJoueur::AddControllerYawInput);
	InputComponent->BindAxis("Lever", this, &ATutoJoueur::AddControllerPitchInput);
}

//Move the player forward and backward
void ATutoJoueur::Avant(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		if (!InventaireVisuel)
		{
			//Find out which way is forward
			FRotator Rotation = Controller->GetControlRotation();
			//limit pitch when walking or falling
			if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
			{
				Rotation.Pitch = 0.0f;
			}
			//add movement in that direction
			const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
			AddMovementInput(Direction, value);
		}
	}
}

//Move the player left and right
void ATutoJoueur::Droite(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		if (!InventaireVisuel)
		{
			//Find out which way is forward
			FRotator Rotation = Controller->GetControlRotation();
			//add movement in that direction
			const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
			AddMovementInput(Direction, value);
		}
	}
}

// TEST : Test the adding of an object
void ATutoJoueur::AjoutObjet()
{
	AddItemWithID(3);
	AddItemWithID(3);
}

// TEST : Test the adding of an object
void ATutoJoueur::SuppressionObjet()
{
	RemoveItemWithID(0);
}

// Return the Number of Item from a specific ID
int32 ATutoJoueur::GetNumberFromID(int32 TheID)
{
	int32 retour = -1;
	for (int32 index = 0; index < Inventaire.Num(); index++)
	{
		if (Inventaire[index].ID == TheID)
		{
			retour = Inventaire[index].Quantite;
			break;
		}
	}
	return retour;
}

// Return the Index of Item in the Inventory from a specific ID
int32 ATutoJoueur::GetItemIndexWithID(int32 TheID)
{
	int32 retour = -1;
	for (int32 index = 0; index < Inventaire.Num(); index++)
	{
		if (Inventaire[index].ID == TheID)
		{
			retour = index;
			break;
		}
	}
	return retour;
}

// Add an Item in the inventory with the specific ID
void ATutoJoueur::AddItemWithID(int32 TheID)
{
	int32 Number = GetNumberFromID(TheID);
	if (Number < NombreMaxItem)
	{
		int32 index = GetItemIndexWithID(TheID);
		Inventaire[index].Quantite++;
	}
	else
	{
		if (GEngine) 
		{ 
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Impossible d'ajouter un Item avec l'iD : " + FString::FromInt(TheID)));
		}

	}
}

// Remove an Item in the inventory with the specific ID
void ATutoJoueur::RemoveItemWithID(int32 TheID)
{
	int32 Number = GetNumberFromID(TheID);
	if (Number > 0)
	{
		int32 index = GetItemIndexWithID(TheID);
		Inventaire[index].Quantite--;
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Impossible de supprimer un Item avec l'iD : " + FString::FromInt(TheID)));
		}

	}
}

// Remove an Item in the inventory with the specific ID and Number
void ATutoJoueur::RemoveItemWithIDAndNumber(int32 TheID, int32 TheNumber)
{
	int32 Num = GetNumberFromID(TheID);
	if (Num - TheNumber >= 0)
	{
		int32 Index = GetItemIndexWithID(TheID);
		Inventaire[Index].Quantite -= TheNumber;
	}
	else
	{
		int32 Index = GetItemIndexWithID(TheID);
		Inventaire[Index].Quantite = 0;
	}
}


// Change the inventory state
void ATutoJoueur::ChangeInventoryState()
{
	InventaireVisuel = !InventaireVisuel;
}

// handle use
void ATutoJoueur::OnUse()
{
	if (InventaireVisuel)
	{
		bool RetourFonction = GetEnoughItem(IndexCraft);
		if (GEngine) 
		{ 
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, RetourFonction ? TEXT("true") : TEXT("false"));
		}
		if (RetourFonction)
		{
			CraftItem(IndexCraft);
		}
	}
	else
	{
		//if we are in a pickup collision
		if (ItemToPickUp)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("picked Up!"));
			}
			//cast the item to a pickup item
			ATutoItem* TheItem = Cast<ATutoItem>(ItemToPickUp);
			if (TheItem)
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Infos retreived, id:" + FString::FromInt(TheItem->info.ID)));
				}
				//update the inventory of the player
				int32 index = GetItemIndexWithID(TheItem->info.ID);
				//the item don't exist, we can add it to the inventory
				if (index == -1)
				{
					FItem NewItem = TheItem->info;
					int32 TheIndex = Inventaire.Add(NewItem);
				}
				//the item already exist, we can update the quantity
				else
				{
					Inventaire[index].Quantite++;
				}
			}
			else
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fail to retreive infos"));
				}
			}
			ItemToPickUp->Destroy();
			ItemToPickUp = nullptr;
		}
	}
}

// Go UP in the crafting list
void ATutoJoueur::MonteCraft()
{
	if (InventaireVisuel && IndexCraft - 1 >= 0)
	{
		IndexCraft--;
	}
}

// Go DOWN in the crafting list
void ATutoJoueur::BaisseCraft()
{
	if (InventaireVisuel && IndexCraft + 1 < Craft.Num())
	{
		IndexCraft++;
	}
}

// Check if we have all the Item to craft the selected Item
bool ATutoJoueur::GetEnoughItem(int32 TheIndex)
{
	bool RetourRequete = true;
	FCraft TheCraft = Craft[TheIndex];

	for (int32 i = 0; i < TheCraft.Requirement.Num(); i++)
	{
		int32 ReturnNumber = GetNumberFromID(TheCraft.Requirement[i].ID);
		if (ReturnNumber < TheCraft.Requirement[i].Quantite)
		{
			RetourRequete = false; 
			return RetourRequete;
		}
	}
	return RetourRequete;
}

void ATutoJoueur::CraftItem(int32 TheIndex)
{
	Craft[TheIndex].Quantite++;
	for (int32 i = 0; i < Craft[TheIndex].Requirement.Num(); i++)
	{
		RemoveItemWithIDAndNumber(Craft[TheIndex].Requirement[i].ID, Craft[TheIndex].Requirement[i].Quantite);
	}
}