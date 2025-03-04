// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IEstrategias.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaDisparadora.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AEstrategiaDisparadora : public AActor, public IIEstrategias
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaDisparadora();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	static bool bMensajeMostrado;


public:
	void Mover(class ANaveEstrategica* PADRIZA, float DeltaTime) override;

	class ANaveEstrategica* NaveEstrategica1;

private:
	// Lista de coordenadas de destino
	TArray<FVector> targetLocations;

	// �ndice de la ubicaci�n de destino actual
	int32 currentTargetIndex;

	// Velocidad de movimiento de la nave
	float speed = 1000.0f;

};
