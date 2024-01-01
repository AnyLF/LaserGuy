// Fill out your copyright notice in the Description page of Project Settings.


#include "CharLaserGuy.h"
#include "GameFramework/CharacterMovementComponent.h"

ACharLaserGuy::ACharLaserGuy()
{
	// Set this character to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	
	ChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("CursorArea"));
	ChildActor->SetupAttachment(RootComponent);
}

void ACharLaserGuy::BeginPlay()
{
	Super::BeginPlay();
}

void ACharLaserGuy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACharLaserGuy::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharLaserGuy::MoveRight);
}

void ACharLaserGuy::MoveForward(float Scale)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, Scale);
}

void ACharLaserGuy::MoveRight(float Scale)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, Scale);
}
