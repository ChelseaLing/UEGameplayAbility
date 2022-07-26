#include "Ability/GASAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UGASAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if(Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxHealth.GetBaseValue());
	}
}

bool UGASAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	return Super::PreGameplayEffectExecute(Data);
}

void UGASAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData & Data)
{
	Super::PostGameplayEffectExecute(Data);
    
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.f, MaxHealth.GetBaseValue()));
		Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0.f, MaxHealth.GetBaseValue()));
	}
}

void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UGASAttributeSet, Health);
    DOREPLIFETIME(UGASAttributeSet, MaxHealth);
    DOREPLIFETIME(UGASAttributeSet, Mana);
}

void UGASAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Health, OldHealth);
}

void UGASAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxHealth, OldMaxHealth);
}

void UGASAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldAttack)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Mana, OldAttack);
}

void UGASAttributeSet::PostInitProperties()
{
	Super::PostInitProperties();
	Health = MaxHealth;
}