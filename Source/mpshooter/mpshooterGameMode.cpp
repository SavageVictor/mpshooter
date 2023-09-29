// Copyright Epic Games, Inc. All Rights Reserved.

#include "mpshooterGameMode.h"
#include "mpshooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AmpshooterGameMode::AmpshooterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
