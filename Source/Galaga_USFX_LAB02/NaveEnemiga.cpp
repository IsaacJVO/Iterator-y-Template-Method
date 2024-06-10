#include "NaveEnemiga.h"

ANaveEnemiga::ANaveEnemiga()
{

	PrimaryActorTick.bCanEverTick = true;

	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;
	Disparar();
}

void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TemplateMethod(DeltaTime);

}

void ANaveEnemiga::Mover(float DeltaTime)
{
}

void ANaveEnemiga::Disparar()
{
}

void ANaveEnemiga::TemplateMethod(float DeltaTime)
{
	Mover(DeltaTime);
}









