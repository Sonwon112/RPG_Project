// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Job.h"
#include "Wizard.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT_API UWizard : public UJob
{
	GENERATED_BODY()

	
public:
	UWizard();
	virtual void Attack(int weaponDamage);
};
