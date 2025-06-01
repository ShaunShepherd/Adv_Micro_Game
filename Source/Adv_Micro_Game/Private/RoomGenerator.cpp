// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGenerator.h"
#include "RoomBase.h"
#include "Components/BoxComponent.h"

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
	USceneComponent* SelectedExitPoint = nullptr;
	USceneComponent* SelectedEntrancePoint = nullptr;
	ARoomBase* NextSpawnedRoom = nullptr;

	//pick random exit and see if it can spawn a room, if it cannot delete it from exit array and pick new one
	for (int i = 0; i < Exits.Num(); i++)
	{
		SelectedExitPoint = Exits[rand() % Exits.Num()];

		ARoomBase* SpawnedRoom = CheckIfExitCanSpawnRoom(SelectedEntrancePoint, SelectedExitPoint);

		if (SpawnedRoom == NULL)
		{
			//no valid rooms for this exit, delete exit from array 
			Exits.Remove(SelectedExitPoint);
		}
		else
		{
			NextSpawnedRoom = SpawnedRoom;

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

			NextSpawnedRoom->CreatePlacementManager();
			break;
		}
	}
}

ARoomBase* ARoomGenerator::CheckIfExitCanSpawnRoom(USceneComponent*& SelectedEntrancePoint, USceneComponent*& SelectedExitPoint)
{
	TArray<TSubclassOf<ARoomBase>> RoomTypesTemp = RoomsToBeSpawned;
	//loop through all room types and check if it overlapps
	for (int i = 0; i < RoomTypesTemp.Num(); i++)
	{
		TSubclassOf<ARoomBase> RandomRoom = RoomTypesTemp[rand() % RoomTypesTemp.Num()];

		ARoomBase* AttemptedSpawnedRoom = this->GetWorld()->SpawnActor<ARoomBase>(RandomRoom); //refactor to randomly pick 
		SetPositionandRotationOfRoom(AttemptedSpawnedRoom, SelectedEntrancePoint, SelectedExitPoint);

		if (!DoesRoomOverlap(AttemptedSpawnedRoom))
		{
			return AttemptedSpawnedRoom;
		}
		else
		{
			RoomTypesTemp.Remove(RandomRoom);
			AttemptedSpawnedRoom->Destroy();
		}
	}
	return nullptr;
}

void ARoomGenerator::SetPositionandRotationOfRoom(ARoomBase* SpawnedRoom, USceneComponent*& SelectedEntrancePoint, USceneComponent*& SelectedExitPoint)
{
	//Select entrance from new room
	TArray<USceneComponent*> PotentialEntrances;
	SpawnedRoom->ExitCheckParent->GetChildrenComponents(false, PotentialEntrances);
	SelectedEntrancePoint = PotentialEntrances[rand() % PotentialEntrances.Num()];

	//Offset and rotate to line up entrance and exit
	SpawnedRoom->ExitLocationParent->SetRelativeRotation(SelectedEntrancePoint->GetComponentRotation());

	float EntranceArrorYaw = SelectedEntrancePoint->GetComponentRotation().Yaw;

	if (EntranceArrorYaw != -180)
	{
		FRotator CurrentRotation = SpawnedRoom->ExitLocationParent->GetComponentRotation();
		CurrentRotation.Yaw += EntranceArrorYaw + 180;
		SpawnedRoom->ExitLocationParent->SetWorldRotation(CurrentRotation);
	}

	SpawnedRoom->ExitLocationParent->SetRelativeLocation(-SelectedEntrancePoint->GetComponentLocation());
	SpawnedRoom->SetActorLocationAndRotation(SelectedExitPoint->GetComponentLocation(), SelectedExitPoint->GetComponentRotation());

}

bool ARoomGenerator::DoesRoomOverlap(ARoomBase* TestedRoom)
{
	TArray<USceneComponent*> OverlappedRooms;
	TestedRoom->OverlapParent->GetChildrenComponents(false, OverlappedRooms);

	TArray<UPrimitiveComponent*> OverlappingComponents;

	for (USceneComponent* Element : OverlappedRooms)
	{
		Cast<UBoxComponent>(Element)->GetOverlappingComponents(OverlappingComponents);
	}

	if (OverlappingComponents.Num() > 0)
	{
		return true;
	}
	return false;
}
