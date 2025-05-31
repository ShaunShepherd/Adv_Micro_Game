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

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_1;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_2;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_3;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_4;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_5;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_6;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_7;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Cube_8;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UStaticMeshComponent* Floor;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, Category = "Componenets")
	UArrowComponent* Arrow;
};
