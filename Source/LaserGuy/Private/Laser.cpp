// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ALaser::ALaser():
    LaserDistance(3000.0f),
    bTraceHit(false),
    LaserHitActor(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Laser = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Laser"));
	Laser->SetupAttachment(RootComponent);

	LaserImpact = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LaserImpact"));
	LaserImpact->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaser::LaserTrace(float& Distance, FVector& Location, FVector& ImpactNormal, AActor*& HitActor, FVector& TraceStart, FVector& TraceEnd)
{
    FVector StartLocation = GetActorLocation();
    FVector EndLocation = StartLocation + (GetActorForwardVector() * LaserDistance);

    float SphereRadius = 15.0f;
    TEnumAsByte<ETraceTypeQuery> TraceChannel = ETraceTypeQuery::TraceTypeQuery1;
    LaserIgnoreActors.Add(this);

    FHitResult HitResult;

        bTraceHit = UKismetSystemLibrary::SphereTraceSingle(
        this,
        StartLocation,
        EndLocation,
        SphereRadius,
        TraceChannel,
        false,
        LaserIgnoreActors,
        EDrawDebugTrace::None,
        HitResult,
        true    // Ignore self
    );

    if (bTraceHit)
    {
        Distance = HitResult.Distance;
        Location = HitResult.Location;
        ImpactNormal = HitResult.ImpactNormal;
        HitActor = HitResult.GetActor();
        TraceStart = HitResult.TraceStart;
        TraceEnd = HitResult.TraceEnd;

        LaserImpact->SetVisibility(true);
        LaserImpact->SetWorldLocation(Location);
        
    }
    else
    {
        LaserImpact->SetVisibility(false);
    }
}

void ALaser::ReflectSelf(FVector ImpactNormal, FVector Location, FVector TraceEnd, FVector TraceStart, AMirror* Mirror)
{
    FVector IncidentVector = TraceEnd - TraceStart;
    FVector ReflectedVector = IncidentVector - 2 * (FVector::DotProduct(IncidentVector, ImpactNormal)) * ImpactNormal;
    FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Location, ReflectedVector * 1000);

    SpawnReflectedLaser(Mirror);
    ReflectedLaser->SetActorLocation(Location);
    ReflectedLaser->SetActorRotation(LookAtRotation);
}

void ALaser::DestroyReflectedLaser()
{
    if (ReflectedLaser)
    {
        ReflectedLaser->DestroyReflectedLaser();
        ReflectedLaser->K2_DestroyActor();
        ReflectedLaser = nullptr;
        ResetSpawnReflectedLaser();
    }
}
