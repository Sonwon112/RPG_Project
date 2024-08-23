// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class RPG_PROJECT_API AWeapon : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,Category=State)
	int weaponDamage;

public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int getWeaponDamage() { return weaponDamage; }

};
