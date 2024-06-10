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
	if (Collection && Collection->NavesEnemigas.IsValidIndex(CurrentIndex)) // Comprueba que la colección y el índice actual sean válidos
	{
		return Collection->NavesEnemigas[CurrentIndex]; // Devuelve la nave enemiga actual
	}
	return nullptr;
}

void UNaveEnemigaIterator::Next()
{
	if (Collection)
	{
		++CurrentIndex; // Incrementa el índice actual
	}
}

bool UNaveEnemigaIterator::IsDone() const
{
	// Devuelve true si el índice actual es mayor o igual al número de naves enemigas
	return !Collection || CurrentIndex >= Collection->NavesEnemigas.Num();
}
