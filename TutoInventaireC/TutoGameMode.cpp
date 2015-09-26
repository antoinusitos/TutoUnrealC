// Fill out your copyright notice in the Description page of Project Settings.

#include "TutoInventaireC.h"
#include "TutoGameMode.h"

ATutoGameMode::ATutoGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//set the default pawn class to our Blurprinted character 
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/AddingContent/Blueprint/BP_TutoJoueur.BP_TutoJoueur_C'")); 
	if (PlayerPawnObject.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}
}

void ATutoGameMode::BeginPlay()
{
	Super::BeginPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}

}