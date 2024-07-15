// Copyright T3Ryan


#include "Character/Decim8EnemyCharacter.h"

#include "AbilitySystem/Decim8AbilitySystemComponent.h"
#include "AbilitySystem/Decim8AttributeSet.h"


ADecim8EnemyCharacter::ADecim8EnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UDecim8AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UDecim8AttributeSet>("AttributeSet");
}

void ADecim8EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}

void ADecim8EnemyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UDecim8AbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

void ADecim8EnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void ADecim8EnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

