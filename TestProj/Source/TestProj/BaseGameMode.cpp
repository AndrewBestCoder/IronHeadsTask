#include "BaseGameMode.h"
#include "Bot'sSystem/MouseMovement.h"

void ABaseGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MouseMovement::Update();
}
