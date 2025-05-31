// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomBase.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ARoomBase::ARoomBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Cube_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_1"));
	Cube_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_2"));
	Cube_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_3"));
	Cube_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_4"));
	Cube_5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_5"));
	Cube_6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_6"));
	Cube_7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_7"));
	Cube_8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_8"));
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_Collision"));

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow_Component"));
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

