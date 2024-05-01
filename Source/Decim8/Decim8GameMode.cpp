// Copyright Epic Games, Inc. All Rights Reserved.

#include "Decim8GameMode.h"
#include "Decim8PlayerController.h"
#include "Decim8Character.h"
#include "UObject/ConstructorHelpers.h"

ADecim8GameMode::ADecim8GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADecim8PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}