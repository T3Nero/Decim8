// Copyright T3Ryan


#include "UI/OverlayWidgetController.h"

#include "AbilitySystem/Decim8AbilitySystemComponent.h"
#include "AbilitySystem/Decim8AttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UDecim8AttributeSet* Attributes = CastChecked<UDecim8AttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(Attributes->GetHealth());
	OnMaxHealthChanged.Broadcast(Attributes->GetMaxHealth());

	OnManaChanged.Broadcast(Attributes->GetMana());
	OnMaxManaChanged.Broadcast(Attributes->GetMaxMana());


}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UDecim8AttributeSet* Attributes = CastChecked<UDecim8AttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Attributes->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Attributes->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Attributes->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		Attributes->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

	Cast<UDecim8AbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[](const FGameplayTagContainer& AssetTags)
		{
			
		}
	);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
