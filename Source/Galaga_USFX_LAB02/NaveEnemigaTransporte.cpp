#include "NaveEnemigaTransporte.h"

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_3.TwinStickUFO_3'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	PrimaryActorTick.bCanEverTick = true;

	// Asignar coordenadas de destino
	targetLocations.Add(FVector(700, -1600, 200));    // Coordenada 1
	targetLocations.Add(FVector(700, 1600, 200));  // Coordenada 2

	currentTargetIndex = 0;

	FireRate = 0.7f;

}
void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaTransporte::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	// Calculate the new position based on the current direction and speed
	FVector newLocation = GetActorLocation();
	FVector targetLocation = targetLocations[currentTargetIndex];
	FVector direction = (targetLocation - newLocation).GetSafeNormal();
	float distance = FVector::Distance(targetLocation, newLocation);
	newLocation += direction * speed * DeltaTime;

	SetActorLocation(newLocation);

	// Verificar si la nave ha llegado a la ubicación de destino actual
	if (distance < 20.0f)
	{
		// Mover a la siguiente ubicación de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
	}
}

void ANaveEnemigaTransporte::Disparar()
{
	// Implementación específica de disparo para NaveEnemigaTransporte
}
