// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "Decim8EffectActor.generated.h"

class UGameplayEffect;
class UAbilitySystemComponent;


UENUM(BlueprintType)
enum class EEffectRemovalPolicy
{
	None,
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class DECIM8_API ADecim8EffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecim8EffectActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called in Blueprint when Applying an Effect to Target (Overlapping a Health Potion etc.)
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnRemoveInfiniteEffect(AActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bDestroyEffectActor = false;

	// Gameplay Effect(s) to Apply (Gameplay Effect created & set in Blueprint)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsToApply;

	// Removal Policy to check whether an Infinite Effect should be removed or not
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;

	// Map to hold the Infinite Gameplay Effect Handle (Required if the Infinite Gameplay Effect is to be removed)
	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveInfiniteEffectHandles;



};
