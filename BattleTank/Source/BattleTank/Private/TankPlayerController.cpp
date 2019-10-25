// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if(!ControlledTank){
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
	
	
}

ATank* ATankPlayerController::GetControlledTank() const //ask player controller : what tank are you controlling ?
{
	return Cast<ATank>(GetPawn()); //cast to type ATank the pawn that playercontroller is controlling..
}


