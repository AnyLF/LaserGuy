// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLaserGuy.h"
#include "Kismet/GameplayStatics.h"

AGameModeLaserGuy::AGameModeLaserGuy() :
	CurrentOverHeatMeter(0),
	OHMeterIncreaseSpeed(0.6),
	bOverHeatMeter(true),
	bLaserAvailable(true)
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

	CurrentOverHeatMeter = 0;
	ReflectedLasers.Empty();
}

void AGameModeLaserGuy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bOverHeatMeter)
	{
		CurrentOverHeatMeter = CurrentOverHeatMeter + OHMeterIncreaseSpeed;
	}
}
