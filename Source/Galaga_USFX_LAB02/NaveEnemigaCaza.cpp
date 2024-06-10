#include "NaveEnemigaCaza.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "ProyectilEnemiga.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_11.TwinStickUFO_11'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	PrimaryActorTick.bCanEverTick = true;


	// Asignar coordenadas de destino
	targetLocations.Add(FVector(-300, 1600, 200));    // Coordenada 1
	targetLocations.Add(FVector(-880, 1000, 200));  // Coordenada 2
	targetLocations.Add(FVector(-510, 560, 200));  // Coordenada 3
	targetLocations.Add(FVector(-880, 40, 200));  // Coordenada 4
	targetLocations.Add(FVector(-510, -480, 200));  // Coordenada 5
	targetLocations.Add(FVector(-880, -950, 200));    // Coordenada 6
	targetLocations.Add(FVector(-300, -1600, 200));    // Coordenada 7
	currentTargetIndex = 0;

	FireRate = 0.7f;

}
void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ANaveEnemigaCaza::Disparar, FireRate, true);


}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{

	FVector newLocation = GetActorLocation();
	FVector targetLocation = targetLocations[currentTargetIndex];
	FVector direction = (targetLocation - newLocation).GetSafeNormal();
	float distance = FVector::Distance(targetLocation, newLocation);
	newLocation += direction * speed * DeltaTime;

	SetActorLocation(newLocation);

	if (distance < 20.0f)
	{
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
	}

	UE_LOG(LogTemp, Warning, TEXT("NaveEnemigaCaza se está moviendo a %s"), *newLocation.ToString());

}

void ANaveEnemigaCaza::Disparar()
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

