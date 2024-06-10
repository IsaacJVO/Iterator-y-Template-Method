
#include "NaveEnemigaHacker.h"
#include "ProyectilEnemiga.h"

ANaveEnemigaHacker::ANaveEnemigaHacker()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_5.TwinStickUFO_5'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	PrimaryActorTick.bCanEverTick = true;


	// Asignar coordenadas de destino
	targetLocations.Add(FVector(1000, -1600, 200));    // Coordenada 1
	targetLocations.Add(FVector(-880, 1600, 200));  // Coordenada 2
	targetLocations.Add(FVector(-800, -1600, 200));  // Coordenada 3
	targetLocations.Add(FVector(1000, 1600, 200));  // Coordenada 4

	currentTargetIndex = 0;

	FireRate = 0.8f;
}

void ANaveEnemigaHacker::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ANaveEnemigaHacker::Disparar, FireRate, true);
}


void ANaveEnemigaHacker::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaHacker::Mover(float DeltaTime)
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

void ANaveEnemigaHacker::Disparar()
{
	// Implementación específica de disparo para NaveEnemigaCaza
	AProyectilEnemiga* Projectile = GetWorld()->SpawnActor<AProyectilEnemiga>(AProyectilEnemiga::StaticClass(), GetActorLocation(), GetActorRotation());
	if (Projectile)
	{
		FVector ForwardDirection = GetActorForwardVector();
		FRotator SpawnRotation = ForwardDirection.Rotation();
		FVector SpawnLocation = GetActorLocation();
		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
		Projectile->Fire();
	}
}

