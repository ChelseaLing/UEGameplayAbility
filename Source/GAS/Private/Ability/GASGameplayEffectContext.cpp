#include "Ability/GASGameplayEffectContext.h"
#include "GameplayEffectTypes.h"

UScriptStruct* FGASGameplayEffectContext::GetScriptStruct() const
{
	return FGameplayEffectContext::StaticStruct();
}

FGASGameplayEffectContext* FGASGameplayEffectContext::Duplicate() const
{
	FGASGameplayEffectContext* NewContext = new FGASGameplayEffectContext();
	*NewContext = *this;
	NewContext->AddActors(Actors);
	if (GetHitResult())
	{
		NewContext->AddHitResult(*GetHitResult(), true);
	}
	NewContext->CustomFloat = CustomFloat;
	return NewContext;
}

bool FGASGameplayEffectContext::NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess)
{
	enum ERepFlag
	{
		REP_Float = 0,
		REP_MAX
	};

	uint8 RepBits = 0;
	if (Ar.IsSaving())
	{
		if (CustomFloat != 0.f) { RepBits |= 1 << REP_Float; }
	}
	Ar.SerializeBits(&RepBits, REP_MAX);
	if (RepBits & (1 << REP_Float)) { Ar << CustomFloat; }
	return Super::NetSerialize(Ar, Map, bOutSuccess);
}
