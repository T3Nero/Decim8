// Copyright T3Ryan


#include "Decim8EffectActor.h"

#include "Components/SphereComponent.h"
#include <AbilitySystemInterface.h>
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Decim8AttributeSet.h"
#include "UI/Decim8WidgetController.h"

// Sets default values
ADecim8EffectActor::ADecim8EffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

}

void ADecim8EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	// TODO:: Change this to apply a Gameplay Effect (GAS). For now using const_cast for testing.
	if(IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UDecim8AttributeSet* Decim8Attributes = Cast<UDecim8AttributeSet>(ASInterface->GetAbilitySystemComponent()->GetAttributeSet(UDecim8AttributeSet::StaticClass()));

		UDecim8AttributeSet* MutableDecim8Attributes = const_cast<UDecim8AttributeSet*>(Decim8Attributes);
		MutableDecim8Attributes->SetHealth(Decim8Attributes->GetHealth() + 25.0f);
		MutableDecim8Attributes->SetMana(Decim8Attributes->GetMana() + 25.0f);

		
		Destroy();
	}

}

void ADecim8EffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void ADecim8EffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ADecim8EffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ADecim8EffectActor::EndOverlap);
	
}


