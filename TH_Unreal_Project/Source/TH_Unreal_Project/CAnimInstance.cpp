// Fill out your copyright notice in the Description page of Project Settings.


#include "CAnimInstance.h"
#include "CPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	ACPlayer* Pawn = Cast<ACPlayer>(TryGetPawnOwner());
	if (Pawn && Pawn->IsValidLowLevel())
	{
		Speed = Pawn->GetCharacterMovement()->Velocity.Size();
		bIsRun = Pawn->bIsRun;
	}
}
