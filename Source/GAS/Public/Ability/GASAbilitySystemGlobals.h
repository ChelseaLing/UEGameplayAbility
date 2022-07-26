#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "GASAbilitySystemGlobals.generated.h"


UCLASS(Blueprintable, config=Game,defaultconfig)
class GAS_API UGASAbilitySystemGlobals  :public UAbilitySystemGlobals
{
	GENERATED_BODY()
	
public:
	UGASAbilitySystemGlobals() {}
	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
	virtual void InitGlobalTags() override;
};
