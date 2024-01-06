// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserGuyGameInstance.h"

void ULaserGuyGameInstance::startgame(FString MapName, FSPlayerInfo Info)
{
	PlayerInfo = Info;
	PlayerInfo.Ready = true;
	GWorld->ServerTravel(FString::Printf(TEXT("/Game/Maps/%s?listen"), *MapName));
}
