#include "BaseGameMode.h"
#include "Bot'sSystem/BotsSystem.h"

ABaseGameMode::ABaseGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	BotsSystem::Update();
}
