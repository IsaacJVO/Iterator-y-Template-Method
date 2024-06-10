// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigaIterator4.h"
#include "Containers/Array.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
AEnemigaIterator4::AEnemigaIterator4()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaIte(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_20.TwinStickUFO_20'"));
	MallaI = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaReloj"));
	RootComponent = MallaI;
	MallaI->SetStaticMesh(MallaIte.Object);

}

// Called when the game starts or when spawned
void AEnemigaIterator4::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigaIterator4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

