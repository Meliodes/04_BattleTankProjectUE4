// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();



}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControllerTank = Cast<ATank>(GetPawn());

	if(PlayerTank)
	{
		// TODO move towards the player

		// Aim towards the player
		ControllerTank->AimAt(PlayerTank->GetActorLocation());

		//Fire if ready
		ControllerTank->Fire();
	}

}







