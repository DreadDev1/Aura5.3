// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/EnemyCharacter.h"

void AEnemyCharacter::HighlightActor()
{
	bHighlighted = true;
}

void AEnemyCharacter::UnHighlightActor()
{
	bHighlighted = false;
}
