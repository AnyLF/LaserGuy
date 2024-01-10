// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor():
	bOpenDoor(false),
	MovingSpeed(5.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bOpenDoor)
	{
		OpenDoor(StaticMesh, OpenedLocation, DeltaTime, MovingSpeed);
	}
	else
	{
		CloseDoor(StaticMesh, DeltaTime, MovingSpeed);
	}
}

void ADoor::OpenDoor(UStaticMeshComponent* Actor, FVector TargetLocation, float DeltaTime, float InterpSpeed)
{
	FVector CurrentLocation = Actor->GetRelativeLocation();

	FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, InterpSpeed);
	
	Actor->SetRelativeLocation(NewLocation);
}

void ADoor::CloseDoor(UStaticMeshComponent* Actor, float DeltaTime, float InterpSpeed)
{
	FVector CurrentLocation = Actor->GetRelativeLocation();

	FVector NewLocation = FMath::VInterpTo(CurrentLocation, FVector(0,0,0), DeltaTime, InterpSpeed);

	Actor->SetRelativeLocation(NewLocation);
}
