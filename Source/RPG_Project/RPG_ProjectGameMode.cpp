// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_ProjectGameMode.h"
#include "RPG_ProjectCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ARPG_ProjectGameMode::ARPG_ProjectGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ARPG_ProjectGameMode::BeginPlay() {
	Super::BeginPlay();
	mode = UIMode::SELECT_JOB;
	setViewPort();
}

void ARPG_ProjectGameMode::setMode(UIMode changedMode) {
	mode = changedMode;
}

void ARPG_ProjectGameMode::setViewPort() {
	if (PlayWidget != nullptr) {
		PlayWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), PlayWidget);
		if (PlayWidgetInstance != nullptr) {
			PlayWidgetInstance->AddToViewport();
		}
	}
}