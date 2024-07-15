// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Decim8AbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class DECIM8_API UDecim8AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	void AbilityActorInfoSet();

protected:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);
	
};
