// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaIterator.h"
#include "NaveEnemigaCollection.h"


void UNaveEnemigaIterator::SetCollection(ANaveEnemigaCollection* InCollection)
{
	Collection = InCollection;
	CurrentIndex = 0;
}

AActor* UNaveEnemigaIterator::GetCurrentNave() const
{
	if (Collection && Collection->NavesEnemigas.IsValidIndex(CurrentIndex)) // Comprueba que la colecci�n y el �ndice actual sean v�lidos
	{
		return Collection->NavesEnemigas[CurrentIndex]; // Devuelve la nave enemiga actual
	}
	return nullptr;
}

void UNaveEnemigaIterator::Next()
{
	if (Collection)
	{
		++CurrentIndex; // Incrementa el �ndice actual
	}
}

bool UNaveEnemigaIterator::IsDone() const
{
	// Devuelve true si el �ndice actual es mayor o igual al n�mero de naves enemigas
	return !Collection || CurrentIndex >= Collection->NavesEnemigas.Num();
}
