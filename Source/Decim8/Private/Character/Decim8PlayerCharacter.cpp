// Copyright T3Ryan


#include "Character/Decim8PlayerCharacter.h"

#include "GameFramework//CharacterMovementComponent.h"
#include "Decim8PlayerState.h"
#include "AbilitySystemComponent.h"

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

void ADecim8PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAbilityActorInfo();
}

void ADecim8PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the client
	InitAbilityActorInfo();
}

void ADecim8PlayerCharacter::InitAbilityActorInfo()
{
	ADecim8PlayerState* Decim8PlayerState = GetPlayerState<ADecim8PlayerState>();
	check(Decim8PlayerState);
	Decim8PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(Decim8PlayerState, this);

	// Init ASC & Attribute Set for the Player
	AbilitySystemComponent = Decim8PlayerState->GetAbilitySystemComponent();
	AttributeSet = Decim8PlayerState->GetAttributeSet();
}
