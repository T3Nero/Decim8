// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "Logging/LogMacros.h"
#include "Decim8PlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IInteractInterface;

UCLASS()
class ADecim8PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADecim8PlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:

	// To add mapping context
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
	/** Input handlers for SetDestination action. */
	void OnInputStarted();
	void OnSetDestinationTriggered();

	/** Input handler for Gamepad/WASD move action */
	void Move(const FInputActionValue& Value);


private:

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> Decim8Context;

	/** Left Mouse Click Move Input Action */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MouseMoveAction;

	/* WASD/Gamepad Move Input Action */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MoveAction;

	// Highlight Actor Using Trace Detection (Actor must implement Interact Interface)
	void InteractTrace();
	
	// Actors which can be interacted with (Defined in InteractTrace())
	TScriptInterface<IInteractInterface> LastActor;
	TScriptInterface<IInteractInterface> ThisActor;

};


