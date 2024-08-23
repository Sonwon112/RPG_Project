// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Job.generated.h"

/**
 * 
 */
UENUM(Blueprintable)
enum class JobName : uint8 {
	NONE UMETA(DisplayName="None"),
	WARRIOR UMETA(DisplayName = "Warrior"),
	WIZARD UMETA(DisplayName = "Wizard"),
	ARCHER UMETA(DisplayName = "Archer")
};

UCLASS(Blueprintable)
class RPG_PROJECT_API UJob : public UObject
{
	GENERATED_BODY()

	
	//virtual void Begin();
public:
	UPROPERTY(EditAnywhere,Category=Job)
	int startHP;
	UPROPERTY(EditAnywhere, Category = Job)
	int defaultDamage;
	UPROPERTY(EditAnywhere, Category = Job)
	JobName jobName;

public:
	//virtual void Tick();
	UJob();
	virtual void Attack(int weaponDamage) {}
	int getStartHP() { return startHP; }
	int getDefaultDamage() { return defaultDamage; }
	UFUNCTION(BlueprintCallable, Category=Job)
	JobName getJobName() { return jobName; }
};
