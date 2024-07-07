// Copyright T3Ryan


#include "UI/OverlayWidgetController.h"
#include "AbilitySystem/Decim8AttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UDecim8AttributeSet* Attributes = CastChecked<UDecim8AttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(Attributes->GetHealth());
	OnMaxHealthChanged.Broadcast(Attributes->GetMaxHealth());

	OnManaChanged.Broadcast(Attributes->GetMana());
	OnMaxManaChanged.Broadcast(Attributes->GetMaxMana());
}
