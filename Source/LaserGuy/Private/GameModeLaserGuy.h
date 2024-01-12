// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraLocation.h"
#include "CharLaserGuy.h"
#include "GameModeLaserGuy.generated.h"

/**
 * 
 */
UCLASS()
class AGameModeLaserGuy : public AGameModeBase
{
	GENERATED_BODY()

public:

	AGameModeLaserGuy();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Laser")
	float CurrentOverHeatMeter;

	UPROPERTY(BlueprintReadWrite, Category = "Laser")
	float OHMeterIncreaseSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Laser")
	bool bOverHeatMeter;

	UPROPERTY(BlueprintReadWrite, Category = "Laser")
	bool bLaserAvailable;

	UPROPERTY(BlueprintReadWrite, Category = "Camera")
	ACameraLocation* CameraLocation;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void RestartLevel();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

};
