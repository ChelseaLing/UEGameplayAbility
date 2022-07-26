#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GASAbilitySystemComponent.generated.h"

UCLASS(ClassGroup = Synth, meta = (BlueprintSpawnableComponent))
class GAS_API UGASAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	//自定义GameplayEffectContext,给蓝图节点用
	UFUNCTION(BlueprintCallable, Category = "GameplayEffects")
	FGameplayEffectContextHandle MakeGASEffectContext(
	AActor* Instigator,
	AActor* EffectCauser,
	UObject* SourceObject,
	const TArray<AActor*>& InActors,
	const float CustomFloat) const;
	
	//添加Tags(非GE方式)
	UFUNCTION(BlueprintCallable, Category = "Tags")
	void ApplyTagsToOwner(const FGameplayTagContainer InTags);

	//移除Tags(非GE方式)
	UFUNCTION(BlueprintCallable, Category = "Tags")
	void RemoveTagsFromOwner(const FGameplayTagContainer InTags);
	
protected:
	virtual void InitializeComponent() override;
	UFUNCTION(BlueprintCallable, Category = "Tags")
	void ApplyOrRemoveTag(const FGameplayTag InTag, bool bApplyOrRemove);
};
