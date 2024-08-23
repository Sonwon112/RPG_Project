// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "RPG_ProjectGameMode.generated.h"

UENUM(Blueprintable)
enum class UIMode : uint8 {
	SELECT_JOB UMETA(DisplayName="Select Job"),
	PLAY UMETA(DisplayName = "Play")
};

UCLASS(minimalapi)
class ARPG_ProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UIMode mode;
public:
	ARPG_ProjectGameMode();
	virtual void BeginPlay();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> PlayWidget;
	UPROPERTY()
	UUserWidget* PlayWidgetInstance;


	UFUNCTION(BlueprintCallable, Category="UI")
	UIMode getMode() { return mode; }
	UFUNCTION(BlueprintCallable, Category="UI")
	void setMode(UIMode mode);

	void setViewPort();
};



