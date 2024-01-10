// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDestructibleObject.h"

// Sets default values
ABaseDestructibleObject::ABaseDestructibleObject():
	Health(100.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MFadedWhite(TEXT("MaterialInstanceConstant'/Game/LevelPrototyping/Materials/MI_FadedWhite.MI_FadedWhite'"));
	MDamageEffect = MFadedWhite.Object;
}

// Called when the game starts or when spawned
void ABaseDestructibleObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseDestructibleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseDestructibleObject::DamageEffect_Implementation()
{
	StaticMesh->SetOverlayMaterial(MDamageEffect);
}

void ABaseDestructibleObject::RemoveDamageEffect_Implementation()
{
	StaticMesh->SetOverlayMaterial(nullptr);
	bTakingDamage = false;
}

void ABaseDestructibleObject::DestroyObject_Implementation()
{
	K2_DestroyActor();
}

void ABaseDestructibleObject::GiveDamage()
{
	if (bTakingDamage == false)
	{
		DamageEffect();
		bTakingDamage = true;
	}

	Health--;

	if (Health<=0)
	{
		DestroyObject();
	}
}

void ABaseDestructibleObject::StopDamage()
{
	RemoveDamageEffect();
}

