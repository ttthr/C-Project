// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TH_UNREAL_PROJECT_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	virtual void NativeUpdateAnimation(float DeltaSeconds);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 bIsRun : 1;
};
