// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP_LearningGameMode.h"
#include "CPP_LearningCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPP_LearningGameMode::ACPP_LearningGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
