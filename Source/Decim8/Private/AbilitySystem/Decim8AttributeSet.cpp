// Copyright T3Ryan


#include "AbilitySystem/Decim8AttributeSet.h"

#include "Net/UnrealNetwork.h"

UDecim8AttributeSet::UDecim8AttributeSet()
{
	// Created from attribute accessors macro (initializes stat values)
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(100.f);
	InitMaxMana(100.f);
}

void UDecim8AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Required when using OnRep to replicate attributes across the network
	DOREPLIFETIME_CONDITION_NOTIFY(UDecim8AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDecim8AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UDecim8AttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDecim8AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UDecim8AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDecim8AttributeSet, Health, OldHealth);
}

void UDecim8AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDecim8AttributeSet, MaxHealth, OldMaxHealth);
}

void UDecim8AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDecim8AttributeSet, Mana, OldMana);
}

void UDecim8AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDecim8AttributeSet, MaxMana, OldMaxMana);
}
