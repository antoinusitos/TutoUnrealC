// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "TutoGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TUTOINVENTAIREC_API ATutoGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	ATutoGameMode(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
