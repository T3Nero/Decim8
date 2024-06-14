// Copyright T3Ryan


#include "Decim8PlayerState.h"

#include "AbilitySystem/Decim8AbilitySystemComponent.h"
#include "AbilitySystem/Decim8AttributeSet.h"

ADecim8PlayerState::ADecim8PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UDecim8AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UDecim8AttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ADecim8PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
