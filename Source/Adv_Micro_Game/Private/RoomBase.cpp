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
	GeometryParent = CreateDefaultSubobject<USceneComponent>(TEXT("GeometryParent"));
	OverlapParent = CreateDefaultSubobject<USceneComponent>(TEXT("OverlapParent"));
	ExitCheckParent = CreateDefaultSubobject<USceneComponent>(TEXT("ExitCheckParent"));

	Door_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door_1"));
	Door_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door_2"));
	Door_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door_3"));
	Door_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door_4"));

	ExitArrow_1 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow_1"));
	ExitArrow_2 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow_2"));
	ExitArrow_3 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow_3"));
	ExitArrow_4 = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitArrow_4"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_Collision"));

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow_Component"));

	DefaultSceneRoot->SetupAttachment(RootComponent);
	GeometryParent->SetupAttachment(DefaultSceneRoot);
	OverlapParent->SetupAttachment(DefaultSceneRoot);
	ExitCheckParent->SetupAttachment(DefaultSceneRoot);
	Arrow->SetupAttachment(DefaultSceneRoot);

	ExitArrow_1->SetupAttachment(ExitCheckParent);
	ExitArrow_2->SetupAttachment(ExitCheckParent);
	ExitArrow_3->SetupAttachment(ExitCheckParent);
	ExitArrow_4->SetupAttachment(ExitCheckParent);

	Door_1->SetupAttachment(ExitArrow_1);
	Door_2->SetupAttachment(ExitArrow_2);
	Door_3->SetupAttachment(ExitArrow_3);
	Door_4->SetupAttachment(ExitArrow_4);


	BoxCollision->SetupAttachment(OverlapParent);

	Arrow->bHiddenInGame = true;
	ExitArrow_1->bHiddenInGame = true;
	ExitArrow_2->bHiddenInGame = true;
	ExitArrow_3->bHiddenInGame = true;
	ExitArrow_4->bHiddenInGame = true;
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

