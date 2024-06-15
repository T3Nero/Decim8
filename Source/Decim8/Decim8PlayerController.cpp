// Copyright Epic Games, Inc. All Rights Reserved.

#include "Decim8PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include <Interaction/InteractInterface.h>


ADecim8PlayerController::ADecim8PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	bReplicates = true;
}

void ADecim8PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	InteractTrace();

}


void ADecim8PlayerController::InteractTrace()
{
	FHitResult Hit;
	
	if(!bShowMouseCursor)
	{
		// Trace Detection Using Gamepad
		APawn* ControlledPawn = GetPawn();
		FVector ForwardVector = ControlledPawn->GetActorRotation().Vector();
		ForwardVector *= 800.f; // The length of the trace from actors location 
		FVector EndTrace = ControlledPawn->GetActorLocation() += ForwardVector;
		FQuat Rot;

		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(ControlledPawn);

		GetWorld()->SweepSingleByChannel(Hit, ControlledPawn->GetActorLocation(), EndTrace, Rot, ECC_Visibility, FCollisionShape::MakeSphere(50.0f), TraceParams);
	}
	else
	{
		// Trace Detection Under Mouse Cursor
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	}

	// Actor to interact with (Highlight)
	LastActor = ThisActor;
	ThisActor = Hit.GetActor();

	/*
	*  Trace Detection. There are several scenarios
	* A. LastActor is null && ThisActor is null
	*	- Do nothing.
	* B. LastActor is null && ThisActor is valid
	*	- Highlight ThisActor
	* C. LastActor is valid && ThisActor is null
	*	- UnHighlight LastActor
	* D. Both actor valid, but LastActor != ThisActor
	*	- UnHighlight LastActor, Highlight ThisActor
	* E. Both actors valid, and are the same actor
	*	- Do nothing
	*/

	if(LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			// Scenario B
			ThisActor->HighlightActor();
		}
		else
		{
			// A: Do Nothing
		}
	}
	else
	{
		if(ThisActor == nullptr)
		{
			// Scenario C
			LastActor->UnHighlightActor();
		}
		else
		{
			if(LastActor != ThisActor)
			{
				// Scenario D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// E: Do Nothing
			}
		}
	}
}

void ADecim8PlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	check(Decim8Context); // check if context is valid before continuing

	//Add Enhanced Input Mapping Context
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(Decim8Context, 0);
	

}

void ADecim8PlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up input action bindings
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MouseMoveAction, ETriggerEvent::Started, this, &ADecim8PlayerController::OnInputStarted);
	EnhancedInputComponent->BindAction(MouseMoveAction, ETriggerEvent::Triggered, this, &ADecim8PlayerController::OnSetDestinationTriggered);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADecim8PlayerController::Move);

}

void ADecim8PlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void ADecim8PlayerController::OnSetDestinationTriggered()
{
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

	// Hit successful if we hit a surface
	if (bHitSuccessful)
	{	
		// Move towards mouse pointer
		APawn* ControlledPawn = GetPawn();
		if (ControlledPawn != nullptr)
		{
			FVector WorldDirection = (Hit.Location - ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
	}
}

void ADecim8PlayerController::Move(const FInputActionValue& Value)
{

	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
	}
}

