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

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDecim8UIWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
