#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "BotActor.generated.h"

USTRUCT(BlueprintType)
struct FPlayerPosStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector LeftPlayerOffset;
	
	UPROPERTY()
	FVector LeftPlayerCurrentPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CenterPlayerOffset;

	UPROPERTY()
	FVector CenterPlayerCurrentPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RightPlayerOffset;

	UPROPERTY()
	FVector RightPlayerCurrentPos;
};

UCLASS()
class TESTPROJ_API ABotActor : public AActor
{
	GENERATED_BODY()

public:

	ABotActor();

	UPROPERTY(EditAnywhere, Category= "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPosition")
	FPlayerPosStruct PlayerPosStruct;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void SetPlayerDefaultPositions(FPlayerPosStruct& PlayerPositions);

	void SetPlayersDebug(FPlayerPosStruct PlayerPositions);
};
