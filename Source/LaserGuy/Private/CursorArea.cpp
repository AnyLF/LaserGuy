// Fill out your copyright notice in the Description page of Project Settings.


#include "CursorArea.h"

// Sets default values
ACursorArea::ACursorArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the Plane static mesh component
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	RootComponent = Plane;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	Plane->SetStaticMesh(PlaneMeshAsset.Object);

	Plane->SetHiddenInGame(true);
	Plane->SetCollisionProfileName(FName("MouseCursor"));

}


