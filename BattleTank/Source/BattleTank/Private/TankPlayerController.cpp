// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const //ask player controller : what tank are you controlling ?
{
	return Cast<ATank>(GetPawn()); //cast to type ATank the pawn that playercontroller is controlling..
}


