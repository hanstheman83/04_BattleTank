// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // forward declaration
class UTankAimingComponent; // forward declaration

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
		// can call function from Blueprint - will get barrel SM in BP
	// Setters (before other methods)
	UFUNCTION(BlueprintCallable, Category = Setup) // a semicolon at end ; will break UFUNCTIONS!!
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup) // a semicolon at end ; will break UFUNCTIONS!!
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();


protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:	
// Called when the game starts or when spawned
	virtual void BeginPlay() override;
// Sets default values for this pawn's properties
	ATank();
	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000; // 1000 m/s TODO find right speed!
	
};
