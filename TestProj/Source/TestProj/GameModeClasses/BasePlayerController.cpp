#include "BasePlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
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

void ABasePlayerController::FindMouseClickPosition()
{
	float MouseX, MouseY;
	GetMousePosition(MouseX, MouseY);
	
	FVector CamLoc;
	FRotator CamRot;
	GetPlayerViewPoint(CamLoc, CamRot);
	

	FVector Forward = CamRot.Vector();
	FVector Right = FRotationMatrix(CamRot).GetScaledAxis(EAxis::Y);
	FVector Up = FRotationMatrix(CamRot).GetScaledAxis(EAxis::Z); 

	int32 SizeX, SizeY;
	GetViewportSize(SizeX, SizeY);


	float NDC_X = (MouseX / SizeX) * 2.f - 1.f;
	float NDC_Y = -(MouseY / SizeY) * 2.f + 1.f;

	FVector RayDir =
		Forward +
		Right * NDC_X +
		(Up * 0.5f)    * NDC_Y;

	RayDir.Normalize();

	FVector PlanePoint = FVector(0, 0, 0);  
	FVector PlaneNormal = FVector::UpVector;

	float Denom = FVector::DotProduct(PlaneNormal, RayDir);

	if (FMath::Abs(Denom) > KINDA_SMALL_NUMBER)
	{
		float T = FVector::DotProduct(
			PlanePoint - CamLoc,
			PlaneNormal
		) / Denom;

		if (T >= 0)
		{
			FVector ClickWorldPos = CamLoc + RayDir * T;

			
			float Radius = 50.f;
			int32 Segments = 32;
			float Thickness = 2.f;
			float Duration = 60.f;

			DrawDebugCircle(
				GetWorld(),
				ClickWorldPos,
				Radius,
				Segments,
				FColor::Green,
				false,
				Duration,
				0,
				Thickness,
				FVector::RightVector,
				FVector::ForwardVector,
				false
			);
		}
	}
}

void ABasePlayerController::MouseClick()
{
	FindMouseClickPosition();
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