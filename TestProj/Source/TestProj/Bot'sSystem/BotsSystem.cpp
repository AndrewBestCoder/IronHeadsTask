#include "BotsSystem.h"

#include "BotActor.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

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

	
	AActor* GlobalCamera =  UGameplayStatics::GetActorOfClass(World, ABotActor::StaticClass());
	if (!GlobalCamera)
	{
		UE_LOG(LogTemp, Error, TEXT("Global camera is not found"));
		return;
	}

	PC->SetViewTarget(GlobalCamera);
}

void BotsSystem::CheckClickDistance(UWorld* World, FVector ClickPosition)
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

	
	ABotActor* BotActor = Cast<ABotActor>(UGameplayStatics::GetActorOfClass(World, ABotActor::StaticClass())); // не очень нравится каст, возможно сделать через интерфейс
	if (BotActor)
	{
		if (FVector::Distance(BotActor->PlayerPosStruct.LeftPlayerCurrentPos, ClickPosition) < 50.0f ||
			FVector::Distance(BotActor->PlayerPosStruct.CenterPlayerCurrentPos, ClickPosition) < 50.0f ||
			FVector::Distance(BotActor->PlayerPosStruct.RightPlayerCurrentPos, ClickPosition) < 50.0f)
		{
			DrawDebug(World, ClickPosition, FColor::Green);
			return;
		}
		DrawDebug(World, ClickPosition, FColor::Red);
	}
}

void BotsSystem::DrawDebug(UWorld* World, FVector Position, FColor Color)
{
	float Radius = 50.f;
	int32 Segments = 32;
	float Thickness = 2.f;
	float Duration = 10.f;

	DrawDebugCircle(
		World,
		Position,
		Radius,
		Segments,
		Color,
		false,
		Duration,
		0,
		Thickness,
		FVector::RightVector,
		FVector::ForwardVector,
		false
	);
}




