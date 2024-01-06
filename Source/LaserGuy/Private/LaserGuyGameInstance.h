// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CharLaserGuy.h"
#include "LaserGuyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ULaserGuyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void startgame(FString MapName, FSPlayerInfo PlayerInfo);

	UPROPERTY(BlueprintReadWrite)
	FSPlayerInfo PlayerInfo;
};
