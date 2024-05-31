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

UCLASS()
class ADecim8PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADecim8PlayerController();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;




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

	FVector CachedDestination;

	float FollowTime; // For how long it has been pressed
};


