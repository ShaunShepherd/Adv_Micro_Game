// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomGenerator.generated.h"

UCLASS()
class ADV_MICRO_GAME_API ARoomGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoomGenerator();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	

};
