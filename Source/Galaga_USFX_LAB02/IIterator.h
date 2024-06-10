// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IIterator.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIIterator : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_LAB02_API IIIterator
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Método para obtener la nave actual del iterador
	virtual class AActor* GetCurrentNave() const = 0;

	// Método para avanzar al siguiente elemento del iterador
	virtual void Next() = 0;

	// Método para verificar si el iterador ha llegado al final
	virtual bool IsDone() const = 0;
};
