// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override; //override - checks can find method up in hirearchy..
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair(); //start the tank moving the barrel so that a shot would hit where the crosshair intersects the world.

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation( FVector& OutHitLocation) const; 

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333f;
	
};
