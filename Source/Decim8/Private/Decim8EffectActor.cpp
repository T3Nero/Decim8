// Copyright T3Ryan


#include "Decim8EffectActor.h"

#include "Components/SphereComponent.h"
#include <AbilitySystemInterface.h>
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Decim8AttributeSet.h"
#include "UI/Decim8WidgetController.h"
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

void ADecim8EffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	// Returns Ability System Component of the Effect Target
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if(TargetASC == nullptr) { return; }

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);

	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


