// Copyright T3Ryan


#include "UI/Decim8WidgetController.h"

void UDecim8WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UDecim8WidgetController::BroadcastInitialValues()
{
}

void UDecim8WidgetController::BindCallbacksToDependencies()
{
}
