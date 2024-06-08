// Copyright T3Ryan


#include "Character/Decim8EnemyCharacter.h"

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
