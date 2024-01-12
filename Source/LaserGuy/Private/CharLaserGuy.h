// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "GameFramework/Actor.h"
#include "Components/ChildActorComponent.h"
#include "NiagaraComponent.h"
#include "Laser.h"
#include "Components/ArrowComponent.h"
#include "CharLaserGuy.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EBodyPart : uint8
{
    BP_Head = 0,
    BP_Body = 1,
    BP_Laser = 2,
    BP_LaserImpact = 3,
    BP_COUNT = 4,
};

USTRUCT(BlueprintType)
struct FSMeshAssetList : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UStaticMesh*> ListStatic;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UNiagaraSystem*> ListNiagra;
};

USTRUCT(BlueprintType)
struct FSBodyPartSelection
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY()
    int Indices[(int)EBodyPart::BP_COUNT];
};

USTRUCT(BlueprintType)
struct FSPlayerInfo
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FSBodyPartSelection BodyParts;

    bool Ready;
};


UCLASS()
class ACharLaserGuy : public ABaseCharacter
{
	GENERATED_BODY()
	
public:

	ACharLaserGuy();

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    virtual void OnConstruction(const FTransform& Transform) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UArrowComponent* LaserSocket;

    UPROPERTY(BlueprintReadOnly)
    FSBodyPartSelection PartSelection;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* PartHead;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* PartBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ALaser* Laser;

    //-------------------------------------------------

    UFUNCTION(BlueprintCallable)
    void ChangeBodyPart(EBodyPart index, int value, bool DirectSet);

    UFUNCTION(BlueprintCallable)
    void LookTo(FVector Target);

    UFUNCTION(BlueprintCallable)
    void FreezeLaserGuy();

    UFUNCTION(BlueprintCallable)
    void UnFreezeLaserGuy();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void FireLaser();

private:

	UPROPERTY(EditAnywhere, Category = "Components")
	UChildActorComponent* ChildActor;

    UMaterialInterface* FreezeMaterial;

    //-------------------------------------------------

	void MoveForward(float Amount);
	void MoveRight(float Amount);

    static FSMeshAssetList* GetBodyPartList(EBodyPart part);

    void UpdateBodyParts();
};
