// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Decim8AttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class DECIM8_API UDecim8AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UDecim8AttributeSet();

	// Must be overriden when using replication for multiplayer games
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

	// Setup attribute data to handle base/current stat values
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Primary Attributes")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Primary Attributes")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Primary Attributes")
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Primary Attributes")
	FGameplayAttributeData MaxMana;


	// Required in multiplayer games to replicate attribute data across server/clients
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData &OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
};
