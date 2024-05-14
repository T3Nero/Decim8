// Copyright T3Ryan


#include "Character/Decim8CharacterBase.h"

// Sets default values
ADecim8CharacterBase::ADecim8CharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void ADecim8CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

