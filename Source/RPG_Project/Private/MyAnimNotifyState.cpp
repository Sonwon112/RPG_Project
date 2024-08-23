// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimNotifyState.h"
#include "GameFramework/Actor.h"
#include "RPG_Project/RPG_ProjectCharacter.h"

void UMyAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	Super::NotifyEnd(MeshComp,Animation);

	if (AActor* Owner = MeshComp->GetOwner()) {
		ARPG_ProjectCharacter* tmp = Cast<ARPG_ProjectCharacter>(Owner);
		if (tmp) {
			tmp->CallAttach();
		}
	}
}