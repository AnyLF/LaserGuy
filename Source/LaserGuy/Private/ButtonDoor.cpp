// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonDoor.h"

// Sets default values
AButtonDoor::AButtonDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AButtonDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AButtonDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

