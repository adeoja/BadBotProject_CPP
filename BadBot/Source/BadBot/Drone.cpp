#include "Drone.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"  

// Sets default values
ADrone::ADrone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultPawn = nullptr;
}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	DefaultPawn = PlayerController->GetPawn();
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector BotLocation = GetActorLocation();
	FRotator BotRotation = GetActorRotation();
	FVector PlayerLocation = DefaultPawn->GetActorLocation();
	
	FRotator LookAtPlayer = UKismetMathLibrary::FindLookAtRotation(BotLocation, PlayerLocation);
	FRotator BotRotator = UKismetMathLibrary::RInterpTo(BotRotation, LookAtPlayer, DeltaTime, InterpSpd);
	SetActorRotation(BotRotator);

	FVector LRifleLocation = Drone->GetSocketLocation("Rifle_L");
	FVector RRifleLocation = Drone->GetSocketLocation("Rifle_R");
	DrawDebugSphere(GetWorld(), LRifleLocation, 5, 12, FColor::Purple, false,0);
	DrawDebugSphere(GetWorld(), RRifleLocation, 5, 12, FColor::Red, false, 0);
}

