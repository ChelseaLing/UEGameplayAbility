#include "Ability/GASAbilityStatic.h"
#include "Abilities/GameplayAbility.h"
#include "Ability/GASGameplayEffectContext.h"

bool UGASAbilityStatic::GetGameplayEffectContextHandleParameter(const FGameplayEffectContextHandle& ContextHandle, float& ContextParameter)
{
	bool bSuccess = false;

	if (!ContextHandle.IsValid()) { return bSuccess; }

	const FGASGameplayEffectContext* EffectContext = static_cast<const FGASGameplayEffectContext*>(ContextHandle.Get());
	if (nullptr == EffectContext) {  return bSuccess; }

	ContextParameter = EffectContext->CustomFloat;
	bSuccess = true;
	
	return bSuccess;
}
