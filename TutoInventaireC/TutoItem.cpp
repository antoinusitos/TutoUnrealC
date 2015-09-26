// Fill out your copyright notice in the Description page of Project Settings.

#include "TutoInventaireC.h"
#include "TutoItem.h"


// Sets default values
ATutoItem::ATutoItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ATutoItem::ATutoItem(const FObjectInitializer& ObjectInitializer)
{
	//Use a sphere as a simple collision representation
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(100.0f);
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ATutoItem::OnBeginOverlap);
	CollisionComp->OnComponentEndOverlap.AddDynamic(this, &ATutoItem::OnEndOverlap);
	RootComponent = CollisionComp;
}

// Called when the game starts or when spawned
void ATutoItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutoItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATutoItem::OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	auto MyPC = Cast<ATutoJoueur>(OtherActor);
	if (MyPC)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("PLAYER ENTER!!"));
		}
		MyPC->ItemToPickUp = this;
	}
}

void ATutoItem::OnEndOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto MyPC = Cast<ATutoJoueur>(OtherActor);
	if (MyPC)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("PLAYER EXIT!!"));
		}
		MyPC->ItemToPickUp = nullptr;
	}

}