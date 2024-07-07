// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Decim8WidgetController.h"

#include "Decim8HUD.generated.h"

/**
 * 
 */

class UDecim8UIWidget;
class UOverlayWidgetController;
class UAbilitySystemComponent;
class UAttributeSet;
struct FWidgetControllerParams;

UCLASS()
class DECIM8_API ADecim8HUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UDecim8UIWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	// Initialises WidgetController & Broadcasts Initial Stat Values then Creates the PlayerHUD & adds to viewport
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDecim8UIWidget> OverlayWidgetClass;

	// Contains Delegates for Broadcasting Attributes to given WBP (Health stats for Health Progress Bar etc.)
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
