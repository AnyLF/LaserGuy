// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "GameFramework/Actor.h"
#include "Components/ChildActorComponent.h"
#include "CharLaserGuy.generated.h"

/**
 * 
 */
UCLASS()
class ACharLaserGuy : public ABaseCharacter
{
	GENERATED_BODY()
	
public:

	ACharLaserGuy();

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);

	UPROPERTY(EditAnywhere, Category = "Components")
	UChildActorComponent* ChildActor;
};
