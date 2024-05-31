// Copyright T3Ryan


#include "Character/Decim8PlayerCharacter.h"
#include "GameFramework//CharacterMovementComponent.h"

ADecim8PlayerCharacter::ADecim8PlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0., 400.0f, .0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
