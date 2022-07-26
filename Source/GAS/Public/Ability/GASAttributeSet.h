#pragma once
#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASAttributeSet.generated.h"

UCLASS()
class  UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual bool IsSupportedForNetworking() const override{ return true; }
	
	//血量
	UPROPERTY(BlueprintReadOnly, Replicated, ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health = 100;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UGASAttributeSet, Health)
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health)

	//最大血量
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth = 100;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UGASAttributeSet, MaxHealth)
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MaxHealth)
	
	//魔法值
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana = 100;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UGASAttributeSet, Mana)
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Mana)
	
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);

protected:
	virtual void PostInitProperties() override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData &Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};