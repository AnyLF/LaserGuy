// Fill out your copyright notice in the Description page of Project Settings.


#include "CharLaserGuy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "LaserGuyGameInstance.h"

static UDataTable* SBodyParts = nullptr;

static const wchar_t* BodyPartNames[] =
{
	TEXT("Head"),
	TEXT("Body"),
	TEXT("Laser"),
	TEXT("LaserImpact")
};

ACharLaserGuy::ACharLaserGuy()
{
	// Set this character to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	
	ChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("CursorArea"));
	ChildActor->SetupAttachment(RootComponent);

	PartHead = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	PartHead->SetupAttachment(GetMesh());

	LaserSocket = CreateDefaultSubobject<UArrowComponent>(TEXT("LaserSocket"));
	LaserSocket->SetupAttachment(PartHead);

	PartBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	PartBody->SetupAttachment(GetMesh());

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_BodyParts(TEXT("/DataTable'/Game/Blueprints/Datas/DT_BodyParts.DT_BodyParts'"));
	SBodyParts = DT_BodyParts.Object;
}

void ACharLaserGuy::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocallyControlled())
	{
		ULaserGuyGameInstance* Instance = Cast<ULaserGuyGameInstance>(GWorld->GetGameInstance());
		if (Instance && Instance->PlayerInfo.Ready)
		{
			PartSelection = Instance->PlayerInfo.BodyParts;
			UpdateBodyParts();
		}
	}
	
}

void ACharLaserGuy::OnConstruction(const FTransform& Transform)
{
	UpdateBodyParts();
}

void ACharLaserGuy::ChangeBodyPart(EBodyPart index, int value, bool DirectSet)
{
	FSMeshAssetList* List = GetBodyPartList(index);
	if (List == nullptr) return;

	int CurrentIndex = PartSelection.Indices[(int)index];

	if (DirectSet)
	{
		CurrentIndex = value;
	}
	else
	{
		CurrentIndex += value;
	}

	int Num = List->ListNiagra.Num() + List->ListStatic.Num();

	if (CurrentIndex < 0)
	{
		CurrentIndex += Num;
	}
	else
	{
		CurrentIndex %= Num;
	}

	PartSelection.Indices[(int)index] = CurrentIndex;

	switch (index)
	{
	case EBodyPart::BP_Head:PartHead->SetStaticMesh(List->ListStatic[CurrentIndex]); break;
	case EBodyPart::BP_Body:PartBody->SetStaticMesh(List->ListStatic[CurrentIndex]); break;
	case EBodyPart::BP_Laser:Laser->Laser->SetAsset(List->ListNiagra[CurrentIndex]); break;
	case EBodyPart::BP_LaserImpact:Laser->LaserImpact->SetAsset(List->ListNiagra[CurrentIndex]); break;
	}
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

FSMeshAssetList* ACharLaserGuy::GetBodyPartList(EBodyPart part)
{
	FString Name = FString::Printf(TEXT("%s"), BodyPartNames[(int)part]);
	return SBodyParts ? SBodyParts->FindRow<FSMeshAssetList>(*Name, nullptr) : nullptr;
}

void ACharLaserGuy::UpdateBodyParts()
{
	ChangeBodyPart(EBodyPart::BP_Head, 0, false);
	ChangeBodyPart(EBodyPart::BP_Body, 0, false);
	if (Laser)
	{
		ChangeBodyPart(EBodyPart::BP_Laser, 0, false);
		ChangeBodyPart(EBodyPart::BP_LaserImpact, 0, false);
	}
}
