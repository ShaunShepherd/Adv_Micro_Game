// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGenerator.h"
#include "RoomBase.h"

// Sets default values
ARoomGenerator::ARoomGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoomGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnStarterRoom();
	SpawnNextRoom();
}

// Called every frame
void ARoomGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoomGenerator::SpawnStarterRoom()
{
	ARoomBase* SpawnedStarterRoom = this->GetWorld()->SpawnActor<ARoomBase>(StarterRoom);

	SpawnedStarterRoom->SetActorLocation(this->GetActorLocation());

	SpawnedStarterRoom->ExitCheckParent->GetChildrenComponents(false, Exits);
}

void ARoomGenerator::SpawnNextRoom()
{
	ARoomBase* NextSpawnedRoom = this->GetWorld()->SpawnActor<ARoomBase>(RoomsToBeSpawned[rand() % RoomsToBeSpawned.Num()]);

	float RandExitNumber = rand() % Exits.Num();

	USceneComponent* SelectedExitPoint = Exits[RandExitNumber];

	NextSpawnedRoom->SetActorLocationAndRotation(SelectedExitPoint->GetComponentLocation(), SelectedExitPoint->GetComponentRotation());
}
