// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "UI/Decim8WidgetController.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */

struct FOnAttributeChangeData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);

UCLASS(BlueprintType, Blueprintable)
class DECIM8_API UOverlayWidgetController : public UDecim8WidgetController
{
	GENERATED_BODY()

public:

	// Broadcasts Delegates in the WBP for setting up Health Globe Progress Bar Attribute Values etc.
	virtual void BroadcastInitialValues() override;

	// Registers AbilitySystemComponent for when Attribute values are changed
	// Listens for stat changes to update Attribute values (Health, Mana etc.) (Calls HealthChanged() Function etc.)
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;

protected:

	// Broadcasts Delegates to update Attribute Values such as; Increasing Health after picking up Health Potion etc.
	void HealthChanged(const FOnAttributeChangeData &Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
	
};
