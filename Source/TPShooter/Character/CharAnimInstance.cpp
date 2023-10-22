// Fill out your copyright notice in the Description page of Project Settings.


#include "CharAnimInstance.h"
#include "TPCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCharAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	TPCharacter = Cast<ATPCharacter>(TryGetPawnOwner());
}

void UCharAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if(TPCharacter == nullptr)
	{
		TPCharacter = Cast<ATPCharacter>(TryGetPawnOwner());
	}
	if(TPCharacter == nullptr) return;

	FVector Velocity = TPCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = TPCharacter->GetCharacterMovement()->IsFalling();

	bIsAccelerating = TPCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}
