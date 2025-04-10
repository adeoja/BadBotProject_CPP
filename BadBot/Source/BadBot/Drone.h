#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	APawn* DefaultPawn = nullptr;
	
	UPROPERTY(EditAnywhere, Category = "Drone Mesh")
	UStaticMeshComponent* DroneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DroneMesh"));

	UPROPERTY(EditAnywhere, Category = "Drone Rotator")
	float InterpSpd = 4;
};
