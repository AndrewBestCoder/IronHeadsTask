#include "BotsSystem.h"

#include "Kismet/GameplayStatics.h"
#include "TestProj/GlobalCamera/GlobalCamera.h"

void BotsSystem::Update()
{
	//UE_LOG(LogTemp, Warning, TEXT("BotsSystem Update Function"));
}

void BotsSystem::SetGlobalCameraView(UWorld* World)
{
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("World is not find"));
		return;
	}

	APlayerController* PC = World->GetFirstPlayerController();
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController is not find"));
		return;
	}

	
	AActor* GlobalCamera =  UGameplayStatics::GetActorOfClass(World, AGlobalCamera::StaticClass());
	if (!GlobalCamera)
	{
		UE_LOG(LogTemp, Error, TEXT("Global camera is not found"));
		return;
	}

	PC->SetViewTarget(GlobalCamera);
}

