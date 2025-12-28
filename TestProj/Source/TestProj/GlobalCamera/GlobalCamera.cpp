


#include "GlobalCamera.h"


// Sets default values
AGlobalCamera::AGlobalCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	RootComponent = CameraComp;
}

