// Copyright T3Ryan


#include "Character/Decim8CharacterBase.h"



// Sets default values
ADecim8CharacterBase::ADecim8CharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* ADecim8CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ADecim8CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

