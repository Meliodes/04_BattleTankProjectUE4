// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"

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

ATank* ATankAIController::GetAIPossessedTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}



