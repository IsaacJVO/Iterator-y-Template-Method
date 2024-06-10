// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"


UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

public:
	ANaveEnemigaEspia();

	FString tipoEspia = "Espia";

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