// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Job.h"
#include "Archer.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_API UArcher : public UJob
{
	GENERATED_BODY()
	
	
public:
	UArcher();
	virtual void Attack(int weaponDamage);
};
