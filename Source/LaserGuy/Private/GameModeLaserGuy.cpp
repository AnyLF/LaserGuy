// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLaserGuy.h"
#include "Kismet/GameplayStatics.h"

AGameModeLaserGuy::AGameModeLaserGuy() :
	LaserStabilization(0),
	LSIncreaseSpeed(0.5)
{

}

void AGameModeLaserGuy::RestartLevel()
{
	FString LevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}

void AGameModeLaserGuy::BeginPlay()
{
	Super::BeginPlay();

	LaserStabilization = 0;
}

void AGameModeLaserGuy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LaserStabilization = LaserStabilization + LSIncreaseSpeed;
}
