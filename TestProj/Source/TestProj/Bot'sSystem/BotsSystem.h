#pragma once


namespace BotsSystem
{
	void Update();

	void SetGlobalCameraView(UWorld* World);

	void CheckClickDistance(UWorld* World, FVector ClickPosition);

	void DrawDebug(UWorld* World, FVector Position, FColor Color);
}
