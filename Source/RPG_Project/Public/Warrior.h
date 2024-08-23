// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Job.h"
#include "Warrior.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_API UWarrior : public UJob
{
	GENERATED_BODY()

	
public:
	UWarrior();
	virtual void Attack(int weaponDamage);
};
