// Copyright T3Ryan


#include "UI/Decim8HUD.h"
#include "UI/Decim8UIWidget.h"
#include "UI/OverlayWidgetController.h"

UOverlayWidgetController* ADecim8HUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if(OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void ADecim8HUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class not set BP_Decim8HUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class not set in BP_Decim8HUD"));

	// Persistent HUD for the Player during gameplay
	UUserWidget* PlayerHUD = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UDecim8UIWidget>(PlayerHUD);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();

	PlayerHUD->AddToViewport();
}
