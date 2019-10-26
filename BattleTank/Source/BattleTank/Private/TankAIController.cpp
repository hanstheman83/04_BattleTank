// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if(!PlayerTank){
		UE_LOG(LogTemp, Warning, TEXT("AIController not finding player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController finding player tank : %s"), *(PlayerTank->GetName()));
	}
	
	
}

ATank* ATankAIController::GetControlledTank() const //ask player controller : what tank are you controlling ?
{
	return Cast<ATank>(GetPawn()); //cast to type ATank the pawn that playercontroller is controlling..
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}
	return Cast<ATank>(PlayerPawn);
}