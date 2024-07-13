// Copyright T3Ryan


#include "Decim8EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

// Sets default values
ADecim8EffectActor::ADecim8EffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root")));

}


// Called when the game starts or when spawned
void ADecim8EffectActor::BeginPlay()
{
	Super::BeginPlay();

	
}

void ADecim8EffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	// Returns Ability System Component of the Effect Target Actor
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if(TargetASC == nullptr) { return; }

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);

	const FActiveGameplayEffectHandle ActiveGameplayEffect = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	// Check if Active Gameplay Effect is applied Infinitely
	const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if(bIsInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		// Add Active Effect to Map so OnRemoveInfiniteEffect knows which Infinite Effect to Remove
		ActiveInfiniteEffectHandles.Add(ActiveGameplayEffect, TargetASC);
	}

	if(bDestroyEffectActor)
	{
		Destroy();
	}
}

void ADecim8EffectActor::OnRemoveInfiniteEffect(AActor* TargetActor)
{
	if(InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if(!IsValid(TargetASC)) { return; }

		// Remove handle(s) from map when Active Gameplay Effect is Removed
		TArray<FActiveGameplayEffectHandle> HandlesToRemove;

		// Loop through all applied Infinite Effects added to the Map
		for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> MapHandle : ActiveInfiniteEffectHandles)
		{
			// Check if Targets Ability System Component matches the Maps Value
			if(TargetASC == MapHandle.Value)
			{
				// Remove the Infinite Gameplay Effect relating to the Targets ASC
				TargetASC->RemoveActiveGameplayEffect(MapHandle.Key, 1);
				HandlesToRemove.Add(MapHandle.Key);
			}
		}

		// Loop through all Active Effect Handles and Remove them from the Map
		for(FActiveGameplayEffectHandle& Handle : HandlesToRemove)
		{
			ActiveInfiniteEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
}


