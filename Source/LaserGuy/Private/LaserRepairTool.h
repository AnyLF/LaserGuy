// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserRepairTool.generated.h"

UCLASS()
class ALaserRepairTool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserRepairTool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;
	//
	//-------------------------------------------------
	//
	UFUNCTION(BlueprintCallable)
	void CollectLaserRepairTool();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void IdleAnimation();
};
