// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserRepairTool.h"
#include "GameModeLaserGuy.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ALaserRepairTool::ALaserRepairTool():
	RepairLevel(25.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserRepairTool"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALaserRepairTool::BeginPlay()
{
	Super::BeginPlay();

	IdleAnimation();
}

// Called every frame
void ALaserRepairTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaserRepairTool::CollectLaserRepairTool()
{
	AGameModeLaserGuy* GM_LaserGuy = Cast<AGameModeLaserGuy>(UGameplayStatics::GetGameMode(this));
	GM_LaserGuy->CurrentOverHeatMeter = UKismetMathLibrary::Max(GM_LaserGuy->CurrentOverHeatMeter - RepairLevel, 0);
	K2_DestroyActor();
}

