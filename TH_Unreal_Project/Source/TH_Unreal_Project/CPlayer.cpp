// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayer.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACPlayer::ACPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//메쉬 회전,위치값
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88.0f), FRotator(0, -90.0f, 0));

	//스프링암 컴포넌트 생성
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	//카메라 컴포넌트 생성
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//캐릭터무브먼트 워크 스피드 초기화
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

}

// Called when the game starts or when spawned
void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACPlayer::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ACPlayer::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ACPlayer::LookUp);
	PlayerInputComponent->BindAction(TEXT("Run"),IE_Pressed, this, &ACPlayer::OnRun);
	PlayerInputComponent->BindAction(TEXT("Run"), IE_Released, this, &ACPlayer::OffRun);
}

void ACPlayer::MoveForward(float Value)
{
	if (Value != 0)
	{
		FVector fDir = UKismetMathLibrary::GetForwardVector(FRotator(0.0f,GetControlRotation().Yaw , 0.0f));
		AddMovementInput(fDir, Value);
	}

}

void ACPlayer::MoveRight(float Value)
{
	if (Value != 0)
	{
		FVector fDir = UKismetMathLibrary::GetRightVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
		AddMovementInput(fDir, Value);
	}
}

void ACPlayer::Turn(float Value)
{
	if (Value != 0)
	{
		AddControllerYawInput(Value);
	}
}

void ACPlayer::LookUp(float Value)
{
	if (Value != 0)
	{
		AddControllerPitchInput(Value);
	}
}

void ACPlayer::OnRun()
{
	bIsRun = true;
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void ACPlayer::OffRun()
{
	bIsRun = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

}

