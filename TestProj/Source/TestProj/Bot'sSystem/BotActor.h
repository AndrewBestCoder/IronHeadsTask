#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestProj/Interfaces/InteractInterface.h"
#include "BotActor.generated.h"

UCLASS()
class TESTPROJ_API ABotActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:

	ABotActor();

	UPROPERTY(EditDefaultsOnly, Category = "StaticMesh")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstance;

	virtual void StartInteract_Implementation() override;

	virtual void EndInteract_Implementation() override;

	void SetColor(FLinearColor Color);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Color")
	FLinearColor BaseColor = FLinearColor::White;
	
	UPROPERTY(EditDefaultsOnly, Category = "Color")
	FLinearColor ActiveColor = FLinearColor::Green;

public:

	virtual void Tick(float DeltaTime) override;
};
