// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TutoDataBase.h"
//#include "TutoJoueur.h"
#include "TutoItem.generated.h"

UCLASS()
class TUTOINVENTAIREC_API ATutoItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATutoItem();

	// constructor of the class 
	ATutoItem(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Sphere collision component
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* CollisionComp;

	// called when something overlap the item
	UFUNCTION()
	void OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	// called when something end overlap the item
	UFUNCTION()
	void OnEndOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Item information
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FItem info;
	
};
