// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIPossessedTank = GetAIPossessedTank();
	if (AIPossessedTank) {
		UE_LOG(LogTemp, Warning, TEXT("%s is AI controlled tank"), *AIPossessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is not possessing a tank"));
	}

	auto TargetTank = GetPlayerTank();
	if (TargetTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is seeing a %s"), *AIPossessedTank->GetName(), *TargetTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	if(GetPlayerTank())
	{
		// TODO move towards the player

		// Aim towards the player
		GetAIPossessedTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}

}

ATank* ATankAIController::GetAIPossessedTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}



