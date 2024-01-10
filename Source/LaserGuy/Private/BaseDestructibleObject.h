// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDestructibleObject.generated.h"

UCLASS()
class ABaseDestructibleObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseDestructibleObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AStats")
	float Health;

	//-------------------------------------------------

	UFUNCTION(BlueprintNativeEvent)
	void DamageEffect();

	UFUNCTION(BlueprintNativeEvent)
	void RemoveDamageEffect();

	UFUNCTION(BlueprintNativeEvent)
	void DestroyObject();

	UFUNCTION(BlueprintCallable)
	void GiveDamage();

	UFUNCTION(BlueprintCallable)
	void StopDamage();

private:

	UMaterialInterface* MDamageEffect;

	bool bTakingDamage;
};
