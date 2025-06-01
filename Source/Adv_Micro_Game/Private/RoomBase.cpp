// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomBase.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ARoomBase::ARoomBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	ExitLocationParent = CreateDefaultSubobject<USceneComponent>(TEXT("ExitLocationParent"));
	GeometryParent = CreateDefaultSubobject<USceneComponent>(TEXT("GeometryParent"));
	OverlapParent = CreateDefaultSubobject<USceneComponent>(TEXT("OverlapParent"));
	ExitCheckParent = CreateDefaultSubobject<USceneComponent>(TEXT("ExitCheckParent"));
	PlaceableLocations = CreateDefaultSubobject<USceneComponent>(TEXT("PlaceableLocations"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_Collision"));

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow_Component"));

	DefaultSceneRoot->SetupAttachment(RootComponent);
	ExitLocationParent->SetupAttachment(DefaultSceneRoot);
	GeometryParent->SetupAttachment(ExitLocationParent);
	OverlapParent->SetupAttachment(ExitLocationParent);
	ExitCheckParent->SetupAttachment(ExitLocationParent);
	Arrow->SetupAttachment(ExitLocationParent);
	PlaceableLocations->SetupAttachment(ExitLocationParent);

	BoxCollision->SetupAttachment(OverlapParent);

	Arrow->bHiddenInGame = true;
}


// Called when the game starts or when spawned
void ARoomBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoomBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

