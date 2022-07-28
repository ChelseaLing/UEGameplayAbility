#pragma once
#include <GameplayTagAssetInterface.h>
#include "CoreMinimal.h"
#include "GASActorWithTags.generated.h"

UCLASS()
class AGASActorWithTags : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	AGASActorWithTags();

	UFUNCTION(BlueprintCallable, Category = GameplayTags)
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	FGameplayTagContainer ActorTag;

public:
	virtual void Tick(float DeltaTime) override;
};