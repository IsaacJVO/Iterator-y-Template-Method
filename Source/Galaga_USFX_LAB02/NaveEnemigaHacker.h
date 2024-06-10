
#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaHacker.generated.h"


UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaHacker : public ANaveEnemiga
{
	GENERATED_BODY()

	
public:
	ANaveEnemigaHacker();

	FString tipoHacker = "Hacker";
public:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	float FireRate;
	FTimerHandle FireTimerHandle;

private:
	// Lista de coordenadas de destino
	TArray<FVector> targetLocations;

	// Índice de la ubicación de destino actual
	int32 currentTargetIndex;

	// Velocidad de movimiento de la nave
	float speed = 1000.0f;

public:
	virtual void Mover(float DeltaTime) override;
	virtual void Disparar() override;

};
