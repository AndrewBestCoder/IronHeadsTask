#pragma once

#include "CoreMinimal.h"
#include <GameFramework/Actor.h>
#include "Camera/CameraComponent.h"
#include "GlobalCamera.generated.h"

UCLASS()
class TESTPROJ_API AGlobalCamera : public AActor
{
	GENERATED_BODY()

	AGlobalCamera();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* CameraComp;
	
};
