// Copyright T3Ryan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decim8EffectActor.generated.h"

class UGameplayEffect;

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
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	// Gameplay Effect to update an Actors Attribute Value Instantly (Potion which increases Health etc.)
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;



};
