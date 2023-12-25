// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraLocation.h"
#include "GameModeLaserGuy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraLocation::ACameraLocation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraLocation::BeginPlay()
{
	Super::BeginPlay();
	AGameModeLaserGuy* GMLaserGuy = Cast<AGameModeLaserGuy>(UGameplayStatics::GetGameMode(this));

	GMLaserGuy->CameraLocation = this;

}

// Called every frame
void ACameraLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

