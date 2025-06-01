// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomGenerator.generated.h"

class ARoomBase;

UCLASS()
class ADV_MICRO_GAME_API ARoomGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoomGenerator();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Rooms")
	TSubclassOf<ARoomBase> StarterRoom;

	UPROPERTY(EditAnywhere, Category = "Rooms")
	TArray<TSubclassOf<ARoomBase>> RoomsToBeSpawned;

	UPROPERTY(EditAnywhere, Category = "Generation Properties")
	int32 RoomAmount;

	TArray<USceneComponent*>Exits;

	void SpawnStarterRoom();

	void SpawnAllRooms();

	void SpawnNextRoom();

protected:
	virtual void BeginPlay() override;
	

};
