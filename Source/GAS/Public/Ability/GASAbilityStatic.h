#pragma once
#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "UObject/Object.h"
#include "GASAbilityStatic.generated.h"

UCLASS()
class UGASAbilityStatic: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	template<class T = UObject>
    static TArray<TWeakObjectPtr<T>> ToWeakObjectArray(const TArray<T*>& InArray);
	UFUNCTION(BlueprintCallable)
	static bool GetGameplayEffectContextHandleParameter(const FGameplayEffectContextHandle& ContextHandle, float& ContextParameter);
};

template<class T>
TArray<TWeakObjectPtr<T>>
UGASAbilityStatic::ToWeakObjectArray(const TArray<T*>& InArray)
{
	TArray<TWeakObjectPtr<T>> RetArray;
	for (T* TmpObject : InArray)
	{
		if (::IsValid(TmpObject))
		{
			RetArray.Add(TWeakObjectPtr<T>(TmpObject));
		}
	}
	return RetArray;
}