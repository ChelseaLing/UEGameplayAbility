#include "Ability/GASAbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Ability/GASAbilityStatic.h"
#include "Ability/GASGameplayEffectContext.h"

FGameplayEffectContextHandle UGASAbilitySystemComponent::MakeGASEffectContext(
	AActor* Instigator,
	AActor* EffectCauser,
	UObject* SourceObject,
	const float CustomFloat) const
{
	FGameplayEffectContextHandle Context = FGameplayEffectContextHandle(UAbilitySystemGlobals::Get().AllocGameplayEffectContext());
	check(AbilityActorInfo.IsValid());
	
	if (!IsValid(Instigator)) { Instigator = AbilityActorInfo->OwnerActor.Get(); }
	if (!IsValid(EffectCauser)) { EffectCauser = AbilityActorInfo->AvatarActor.Get(); }
	Context.AddInstigator(Instigator, EffectCauser);
	Context.AddSourceObject(SourceObject);
	//自定义参数
	if (FGASGameplayEffectContext* EffectContext = static_cast<FGASGameplayEffectContext*>(Context.Get()))
	{
		EffectContext->CustomFloat = CustomFloat;
	}
	
	return Context;
}

void UGASAbilitySystemComponent::ApplyTagsToOwner(const FGameplayTagContainer InTags)
{
	if(!InTags.IsValid()) { return; }
	
	for (auto It = InTags.CreateConstIterator(); It; ++It)
	{
		const FGameplayTag& TmpTag = *It;
		ApplyOrRemoveTag(TmpTag, true);
	}
}

void UGASAbilitySystemComponent::RemoveTagsFromOwner(const FGameplayTagContainer InTags)
{
	if(!InTags.IsValid()) { return; }
	
	for (auto It = InTags.CreateConstIterator(); It; ++It)
	{
		const FGameplayTag& TmpTag = *It;
		ApplyOrRemoveTag(TmpTag, false);
	}
}

void UGASAbilitySystemComponent::ApplyOrRemoveTag(const FGameplayTag InTag, const bool bApplyOrRemove)
{
	const bool bIsAuthority = GetOwnerRole() == ROLE_Authority;
	
	if (bApplyOrRemove)
	{
		if (!HasMatchingGameplayTag(InTag))
		{
			AddLooseGameplayTag(InTag);
			if (bIsAuthority)
			{
				AddMinimalReplicationGameplayTag(InTag);
			}
		}
		return;
	}
	
	if (HasMatchingGameplayTag(InTag))
	{
		RemoveLooseGameplayTag(InTag);
		if (bIsAuthority)
		{
			RemoveMinimalReplicationGameplayTag(InTag);
		}
	}
}

void UGASAbilitySystemComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}