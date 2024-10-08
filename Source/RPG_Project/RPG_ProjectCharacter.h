// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPG_ProjectGameMode.h"
#include "Public/Job.h"
#include "Public/Weapon.h"
#include "RPG_ProjectCharacter.generated.h"

UCLASS(config=Game)
class ARPG_ProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ARPG_ProjectCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Job)
	UJob* playerJob;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Job)
	FName weaponComponentName = "none";


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MovementSpeedValue)
	float runSpeed = 1000.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MovementSpeedValue)
	float walkSpeed = 500.0f;

	bool isDraw = false;
	bool hasWeapon = false;

protected:
	bool isRun = false;


	ARPG_ProjectGameMode* MyMode;
	/** Resets HMD orientation in VR. */
	void OnResetVR();
	
	/** Convert Speed*/
	void OnRun();
	void OnWalk();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	
	void DrawWeaponOrAttack();


	virtual void BeginPlay();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable,Category="Job")
	void setJob(JobName jobName);
	void logJobName();

	UFUNCTION(BlueprintCallable,Category="Weapon")
	virtual void CallAttach();

	UFUNCTION(BlueprintCallable,Category="Weapon")
	void AttachActorToHand(AActor* ActorToAttach);
	UFUNCTION(BlueprintCallable,Category="Weapon")
	bool GetDrawState() { return isDraw; }
	UFUNCTION(BlueprintCallable,Category="Weapon")
	bool GetHasWeapon() { return hasWeapon; }
	
};

