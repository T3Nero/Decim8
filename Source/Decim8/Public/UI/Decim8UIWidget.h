// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "UINavWidget.h"
#include "Decim8UIWidget.generated.h"

/**
 * 
 */
UCLASS()
class DECIM8_API UDecim8UIWidget : public UUINavWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	// Called from InitOverlay in Decim8HUD class
	// Sets Widget Controllers in PlayerHUD Event Graph for Broadcasting Attributes (Health etc.)
	UFUNCTION(BlueprintImplementableEvent)
	void InitWidgetController();
};
