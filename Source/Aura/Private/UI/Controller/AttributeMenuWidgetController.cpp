// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Controller/AttributeMenuWidgetController.h"


#include "Framework/AbilitySystem/Attributes/AuraAttributeSet.h"
#include "Framework/AbilitySystem/Attributes/Data/AttributeInfo.h"
#include "AuraGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{

}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{

	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);

	for (TTuple<FGameplayTag, FGameplayAttribute(*)()>&Mapping Tags to Attributes Pair : AS->TagsToAttributes)
	{
		FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);
	}
}
