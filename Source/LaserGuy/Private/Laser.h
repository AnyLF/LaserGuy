// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "Mirror.h"
#include "Laser.generated.h"

class AGameModeLaserGuy;

UCLASS()
class ALaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UNiagaraComponent* Laser;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UNiagaraComponent* LaserImpact;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float LaserDistance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bTraceHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	TArray<AActor*> LaserIgnoreActors;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AGameModeLaserGuy* Gamemode;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AActor* LaserHitActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ALaser* ReflectedLaser;
	//
	//-------------------------------------------------
	//
	UFUNCTION(BlueprintCallable, Category = "Trace")
	void LaserTrace(float& Distance, FVector& Location, FVector& ImpactNormal, AActor*& HitActor, FVector& TraceStart, FVector& TraceEnd);

	UFUNCTION(BlueprintCallable)
	void ReflectSelf(FVector ImpactNormal, FVector Location, FVector TraceEnd, FVector TraceStart, AMirror* Mirror);

	UFUNCTION(BlueprintCallable)
	void DestroyReflectedLaser();

	UFUNCTION(BlueprintImplementableEvent)
	void UnFreeze();

	UFUNCTION(BlueprintImplementableEvent)
	void Freeze();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnReflectedLaser(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetSpawnReflectedLaser();


};
