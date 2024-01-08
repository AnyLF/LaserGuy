// Fill out your copyright notice in the Description page of Project Settings.


#include "Mirror.h"

// Sets default values
AMirror::AMirror()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mirror"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMirror::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMirror::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

