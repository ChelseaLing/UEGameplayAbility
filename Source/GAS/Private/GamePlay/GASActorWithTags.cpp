#include "GamePlay/GASActorWithTags.h"

AGASActorWithTags::AGASActorWithTags()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGASActorWithTags::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = ActorTag;
}

void AGASActorWithTags::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGASActorWithTags::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

