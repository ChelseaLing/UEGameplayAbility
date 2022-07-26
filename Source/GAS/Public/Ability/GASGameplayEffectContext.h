#pragma once
#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GASGameplayEffectContext.generated.h"

USTRUCT(BlueprintType)
struct GAS_API FGASGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()
	
	virtual UScriptStruct*	GetScriptStruct() const override;
	virtual FGASGameplayEffectContext*	Duplicate() const override;
	virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override;

	//自定义数据
	UPROPERTY(BlueprintReadWrite)
	float CustomFloat;
};

template<>
struct TStructOpsTypeTraits<FGASGameplayEffectContext> : TStructOpsTypeTraitsBase2<FGASGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
};
