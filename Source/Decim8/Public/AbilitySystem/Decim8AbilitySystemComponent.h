// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Decim8AbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /* Asset Tags */);

/**
 * 
 */
UCLASS()
class DECIM8_API UDecim8AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	// Adds Delegates which are called when a Gameplay Effect is Applied
	void AbilityActorInfoSet();

	// Delegate to Broadcast Gameplay Tags to the Widget Controller
	FEffectAssetTags EffectAssetTags;

protected:


	/*
	 * Called from the Delegate whenever a Gameplay Effect is Applied
	 * Allows us to Broadcast which Gameplay Tags are assigned to currently applied Effects
	 */
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);
	
};
