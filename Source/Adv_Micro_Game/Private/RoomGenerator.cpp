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
	SpawnAllRooms();
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

void ARoomGenerator::SpawnAllRooms()
{
	for (int i = 0; i < RoomAmount; i++)
	{
		SpawnNextRoom();
	}
}

void ARoomGenerator::SpawnNextRoom()
{
	//Spawn a new room from the rooms to be spawned array
	ARoomBase* NextSpawnedRoom = this->GetWorld()->SpawnActor<ARoomBase>(RoomsToBeSpawned[rand() % RoomsToBeSpawned.Num()]);

	//Selecte an exit from the current room
	USceneComponent* SelectedExitPoint = Exits[rand() % Exits.Num()];

	//Select entrance from new room
	TArray<USceneComponent*> PotentialEntrances;
	NextSpawnedRoom->ExitCheckParent->GetChildrenComponents(false, PotentialEntrances);
	USceneComponent* SelectedEntrancePoint = PotentialEntrances[rand() % PotentialEntrances.Num()];

	//Offset and rotate to line up entrance and exit
	NextSpawnedRoom->ExitLocationParent->SetRelativeRotation(SelectedEntrancePoint->GetComponentRotation());

	float EntranceArrorYaw = SelectedEntrancePoint->GetComponentRotation().Yaw;

	if (EntranceArrorYaw != -180)
	{
		FRotator CurrentRotation = NextSpawnedRoom->ExitLocationParent->GetComponentRotation();
		CurrentRotation.Yaw += EntranceArrorYaw + 180;
		NextSpawnedRoom->ExitLocationParent->SetWorldRotation(CurrentRotation);
	}

	NextSpawnedRoom->ExitLocationParent->SetRelativeLocation(-SelectedEntrancePoint->GetComponentLocation());
	NextSpawnedRoom->SetActorLocationAndRotation(SelectedExitPoint->GetComponentLocation(), SelectedExitPoint->GetComponentRotation());

	//delete the wall at the selected entrance adn exit
	SelectedEntrancePoint->GetChildComponent(0)->DestroyComponent();
	SelectedExitPoint->GetChildComponent(0)->DestroyComponent();
	
	Exits.Remove(SelectedExitPoint);

	TArray<USceneComponent*>NextSpawnedRoomExits;
	NextSpawnedRoom->ExitCheckParent->GetChildrenComponents(false, NextSpawnedRoomExits);
	NextSpawnedRoomExits.Remove(SelectedEntrancePoint);
	Exits.Append(NextSpawnedRoomExits);

	SelectedEntrancePoint->DestroyComponent(false);
	SelectedExitPoint->DestroyComponent(false);
}
