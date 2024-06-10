// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemigaIterator.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API AEnemigaIterator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigaIterator();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Reloj, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MallaI;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
