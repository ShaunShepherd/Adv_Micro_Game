// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomBase.generated.h"

class UBoxComponent;
class UArrowComponent;

UCLASS()
class ADV_MICRO_GAME_API ARoomBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoomBase();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	USceneComponent* ExitLocationParent;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	USceneComponent* ExitCheckParent;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	USceneComponent* OverlapParent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "Obstacle Placement Properties")
	float PlacementBudget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Componenets")
	USceneComponent* PlaceableLocations;

	UFUNCTION(BlueprintImplementableEvent, Category = "Create Placement Manager")
	void CreatePlacementManager();

protected:
	virtual void BeginPlay() override;

	//Scene parents
	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	USceneComponent* GeometryParent;

	//Other useful componenets
	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UArrowComponent* Arrow;
};
