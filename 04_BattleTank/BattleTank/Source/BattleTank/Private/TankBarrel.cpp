// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

UTankBarrel::UTankBarrel()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshToUse(TEXT("/Game/TankParts/tank_fbx_Barrel"));
	if (MeshToUse.Succeeded())
	{
		SetStaticMesh(MeshToUse.Object);
	}
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	
}

