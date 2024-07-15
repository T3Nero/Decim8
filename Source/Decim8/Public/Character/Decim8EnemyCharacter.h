// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "Character/Decim8CharacterBase.h"
#include "Interaction/InteractInterface.h"
#include "Decim8EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DECIM8_API ADecim8EnemyCharacter : public ADecim8CharacterBase, public IInteractInterface
{
	GENERATED_BODY()

public:

	ADecim8EnemyCharacter();

	// overriden from Interact Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:

	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
	
};
