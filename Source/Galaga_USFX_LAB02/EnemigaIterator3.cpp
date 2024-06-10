// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigaIterator3.h"
#include "Containers/Array.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
AEnemigaIterator3::AEnemigaIterator3()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaIte(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_19.TwinStickUFO_19'"));
	MallaI = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaReloj"));
	RootComponent = MallaI;
	MallaI->SetStaticMesh(MallaIte.Object);

}

// Called when the game starts or when spawned
void AEnemigaIterator3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigaIterator3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

