

#pragma once

#include "CoreMinimal.h"
#include "TestProj/TestProjGameModeBase.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJ_API ABaseGameMode : public ATestProjGameModeBase
{
	GENERATED_BODY()

	ABaseGameMode();

	

public:

	UPROPERTY(EditDefaultsOnly, Category="BotTransform")
	FVector BotPosition;
	
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
