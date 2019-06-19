// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

UTankTurret::UTankTurret()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshToUse(TEXT("/Game/TankParts/tank_fbx_Turret"));
	if (MeshToUse.Succeeded())
	{
		SetStaticMesh(MeshToUse.Object);
	}
}

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = RelativeSpeed * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto TurretRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, TurretRotation, 0));
}


