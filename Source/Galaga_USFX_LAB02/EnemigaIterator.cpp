// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigaIterator.h"
#include "Containers/Array.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
AEnemigaIterator::AEnemigaIterator()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaIte(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_17.TwinStickUFO_17'"));
	MallaI = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaReloj"));
	RootComponent = MallaI;
	MallaI->SetStaticMesh(MallaIte.Object);

}

// Called when the game starts or when spawned
void AEnemigaIterator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigaIterator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

