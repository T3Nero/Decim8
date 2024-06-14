// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "Character/Decim8CharacterBase.h"
#include "Decim8PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DECIM8_API ADecim8PlayerCharacter : public ADecim8CharacterBase
{
	GENERATED_BODY()

public:

	ADecim8PlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:

	void InitAbilityActorInfo();

	
};
