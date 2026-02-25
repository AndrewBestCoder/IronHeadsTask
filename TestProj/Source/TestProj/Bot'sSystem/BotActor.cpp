


#include "BotActor.h"

#include "DrawDebugHelpers.h"
#include "Misc/MapErrors.h"


ABotActor::ABotActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	RootComponent = Camera;
}


void ABotActor::BeginPlay()
{
	Super::BeginPlay();

	SetPlayerDefaultPositions(PlayerPosStruct);
	SetPlayersDebug(PlayerPosStruct);
}


void ABotActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABotActor::SetPlayerDefaultPositions(FPlayerPosStruct& PlayerPositions)
{
	PlayerPositions.LeftPlayerCurrentPos.X = GetActorLocation().X + PlayerPositions.LeftPlayerOffset.X;
	PlayerPositions.LeftPlayerCurrentPos.Y = GetActorLocation().Y + PlayerPositions.LeftPlayerOffset.Y;
	
	PlayerPositions.CenterPlayerCurrentPos.X = GetActorLocation().X + PlayerPositions.CenterPlayerOffset.X;
	PlayerPositions.CenterPlayerCurrentPos.Y = GetActorLocation().Y + PlayerPositions.CenterPlayerOffset.Y;
	
	PlayerPositions.RightPlayerCurrentPos.X = GetActorLocation().X + PlayerPositions.RightPlayerOffset.X;
	PlayerPositions.RightPlayerCurrentPos.Y = GetActorLocation().Y + PlayerPositions.RightPlayerOffset.Y;
}

void ABotActor::SetPlayersDebug(FPlayerPosStruct PlayerPositions)
{
	float Radius = 50.f;
	int32 Segments = 32;
	float Thickness = 2.f;
	float Duration = 60.f;

	DrawDebugCircle(
		GetWorld(),
		PlayerPositions.LeftPlayerCurrentPos,
		Radius,
		Segments,
		FColor::Blue,
		false,
		Duration,
		0,
		Thickness,
		FVector::RightVector,
		FVector::ForwardVector,
		false
	);

	DrawDebugCircle(
		GetWorld(),
		PlayerPositions.CenterPlayerCurrentPos,
		Radius,
		Segments,
		FColor::Blue,
		false,
		Duration,
		0,
		Thickness,
		FVector::RightVector,
		FVector::ForwardVector,
		false
	);

	DrawDebugCircle(
		GetWorld(),
		PlayerPositions.RightPlayerCurrentPos,
		Radius,
		Segments,
		FColor::Blue,
		false,
		Duration,
		0,
		Thickness,
		FVector::RightVector,
		FVector::ForwardVector,
		false
	);
}

