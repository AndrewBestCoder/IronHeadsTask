#include "BasePlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "TestProj/Interfaces/InteractInterface.h"

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseClick", IE_Pressed, this, &ABasePlayerController::MouseClick);
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetCursor();
}

void ABasePlayerController::MouseClick()
{
	AActor* OtherActor = CursorLineTrace();
	if (OtherActor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
	{
		if (InteractActor)
		{
			IInteractInterface::Execute_EndInteract(InteractActor);
			InteractActor = nullptr;
		}
		InteractActor = OtherActor;
		IInteractInterface::Execute_StartInteract(InteractActor);
	}
	else if (InteractActor)
	{
		IInteractInterface::Execute_EndInteract(InteractActor);
		InteractActor = nullptr;
	}
}

void ABasePlayerController::SetCursor()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController is not find"));
		return;
	}

	PC->SetShowMouseCursor(true);
}

AActor* ABasePlayerController::CursorLineTrace()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!PC) return nullptr;

	FHitResult Hit;

	bool bHit = PC->GetHitResultUnderCursor(
		ECC_Visibility,
		false,   
		Hit
	);

	if (bHit)
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor)
		{
			return HitActor;
		}
	}
	return nullptr;
}