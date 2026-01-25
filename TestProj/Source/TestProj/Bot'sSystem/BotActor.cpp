


#include "BotActor.h"

#include "Misc/MapErrors.h"


ABotActor::ABotActor()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;
}

void ABotActor::StartInteract_Implementation()
{
	SetColor(ActiveColor);
}

void ABotActor::EndInteract_Implementation()
{
	SetColor(BaseColor);
}

void ABotActor::SetColor(FLinearColor Color)
{
	if (!MaterialInstance) return;

	MaterialInstance->SetVectorParameterValue("Color", Color);
}


void ABotActor::BeginPlay()
{
	Super::BeginPlay();

	UMaterialInterface* BaseMaterial = StaticMesh->GetMaterial(0);
	if (!BaseMaterial)
	{
		UE_LOG(LogTemp, Warning, TEXT("Material not found"));
		return;
	}
	
	MaterialInstance = UMaterialInstanceDynamic::Create(BaseMaterial, this);
	
	StaticMesh->SetMaterial(0, MaterialInstance);
	
	MaterialInstance->SetVectorParameterValue("Color", BaseColor);
}


void ABotActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

