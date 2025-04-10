// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Drone.generated.h"


UCLASS()
class BADBOT_API ADrone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY()
	APawn* DefaultPawn;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Drone;

	UPROPERTY(EditAnywhere)
	float InterpSpd;
};
