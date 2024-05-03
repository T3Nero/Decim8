// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Decim8CharacterBase.generated.h"

UCLASS(Abstract)
class DECIM8_API ADecim8CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADecim8CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

};
