#include "Ability/GASAbilitySystemGlobals.h"
#include "Ability/GASGameplayEffectContext.h"

FGameplayEffectContext* UGASAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FGASGameplayEffectContext();
}

void UGASAbilitySystemGlobals::InitGlobalTags()
{
	Super::InitGlobalTags();
}
