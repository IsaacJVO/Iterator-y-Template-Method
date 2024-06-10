// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaCollection.generated.h"

UCLASS()
class GALAGA_USFX_LAB02_API ANaveEnemigaCollection : public AActor
{
	GENERATED_BODY()
	
public:
    TArray<AActor*> NavesEnemigas;

    void AddNave(AActor* Nave)
    {
        NavesEnemigas.Add(Nave);
    }
};
