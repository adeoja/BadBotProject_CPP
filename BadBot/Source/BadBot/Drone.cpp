#include "Drone.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"  

// Sets default values
ADrone::ADrone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Turn drone mesh into root component
	RootComponent = DroneMesh;  
}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();

	if(APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		DefaultPawn = PlayerController->GetPawn();
	}
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Safety check
	if(!DefaultPawn || !DroneMesh) 
	{
		UE_LOG(LogTemp, Error, TEXT("Drone mesh or DefaultPawn Missing"));
		return; // Exit early if critical components are missing
	}

	// Get bot and player pawn locations/rotation
	FVector BotLocation = GetActorLocation();
	FRotator BotRotation = GetActorRotation();
	FVector PlayerLocation = DefaultPawn->GetActorLocation();

	// Calculate new rotation and add interpolation
	FRotator LookAtPlayer = UKismetMathLibrary::FindLookAtRotation(BotLocation, PlayerLocation);
	FRotator BotRotator = UKismetMathLibrary::RInterpTo(BotRotation, LookAtPlayer, DeltaTime, InterpSpd);
	SetActorRotation(BotRotator);

	// Get socket locations, then place debug sphere at that location
	FVector LRifleLocation = DroneMesh->GetSocketLocation("Rifle_L");
	FVector RRifleLocation = DroneMesh->GetSocketLocation("Rifle_R");
	DrawDebugSphere(GetWorld(), LRifleLocation, 5, 12, FColor::Purple, false,0);
	DrawDebugSphere(GetWorld(), RRifleLocation, 5, 12, FColor::Red, false, 0);
}

