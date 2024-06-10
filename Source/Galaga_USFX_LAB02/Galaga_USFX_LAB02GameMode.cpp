#include "Galaga_USFX_LAB02GameMode.h"
#include "Galaga_USFX_LAB02Pawn.h"
//************OBSERVER****************
#include "Reloj.h"
#include "Publicador.h"
#include "TorreEifel.h"
#include "NaveEstado.h"
//***********STRATERGY****************
#include "NaveEstrategica.h"
#include "EstrategiaEspiadora.h"
#include "EstrategiaAyudante.h"
#include "EstrategiaDisparadora.h"
//**************FACADE****************
#include "FacadeNaves.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
//***************ITERATOR*************
#include "EnemigaIterator.h"
#include "EnemigaItertor2.h"
#include "EnemigaIterator3.h"
#include "EnemigaIterator4.h"
#include "EnemigaIterator5.h"
//*************COLLECTION*************
#include "NaveEnemigaCollection.h"
#include "NaveEnemigaIterator.h"


AGalaga_USFX_LAB02GameMode::AGalaga_USFX_LAB02GameMode()
{
    // set default pawn class to our character class

    PrimaryActorTick.bCanEverTick = true;

    DefaultPawnClass = AGalaga_USFX_LAB02Pawn::StaticClass();


    //E_Reloj = 0.0f;
    //bEstrategiasCambiadas = false;

}

void AGalaga_USFX_LAB02GameMode::BeginPlay()
{
    Super::BeginPlay();

    //************************************  ITERATOR    *********************************************

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("ITERADOR INICIADO EN EL BEGIN_PLAY."));
    }

    ANaveEnemigaCollection* NaveCollection = GetWorld()->SpawnActor<ANaveEnemigaCollection>();

    if (!NaveCollection)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("NO SE CREO LA COLECCION."));
        }
        return;
    }

    FVector ubicacionNavesIterator[] = {
        FVector(-2500.0f, -1000.0f, 200.0f),
        FVector(-2500.0f, -700.0f, 200.0f),
        FVector(-2500.0f, -400.0f, 200.0f),
        FVector(-2500.0f, -100.0f, 200.0f),
        FVector(-2500.0f, 200.0f, 200.0f)
    };
    FRotator rotacionNavesIterator = FRotator(0.0f, 0.0f, 0.0f);

    for (int32 i = 0; i < 5; ++i)
    {
        AActor* Nave = nullptr;
        switch (i)
        {
        case 0:
            Nave = GetWorld()->SpawnActor<AEnemigaIterator>(ubicacionNavesIterator[i], rotacionNavesIterator);
            break;
        case 1:
            Nave = GetWorld()->SpawnActor<AEnemigaItertor2>(ubicacionNavesIterator[i], rotacionNavesIterator);
            break;
        case 2:
            Nave = GetWorld()->SpawnActor<AEnemigaIterator3>(ubicacionNavesIterator[i], rotacionNavesIterator);
            break;
        case 3:
            Nave = GetWorld()->SpawnActor<AEnemigaIterator4>(ubicacionNavesIterator[i], rotacionNavesIterator);
            break;
        case 4:
            Nave = GetWorld()->SpawnActor<AEnemigaIterator5>(ubicacionNavesIterator[i], rotacionNavesIterator);
            break;
        default:
            break;
        }
        if (Nave)
        {
            NaveCollection->AddNave(Nave);
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("NAVE ESTA EN EL INDICE: %d"), i));
            }
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("NAVE NO ESTA EN EL INDICE: %d"), i));
            }
        }
    }

    UNaveEnemigaIterator* NaveIteratorInstance = NewObject<UNaveEnemigaIterator>();
    if (!NaveIteratorInstance)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ITERADOR SIN SERVIR."));
        }
        return;
    }
    NaveIteratorInstance->SetCollection(NaveCollection);

    int32 NaveIndex = 0;

    while (!NaveIteratorInstance->IsDone())
    {
        AActor* Nave = NaveIteratorInstance->GetCurrentNave();
        if (Nave)
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, FString::Printf(TEXT("NAVE ITERADA EN: %d"), NaveIndex));
            }

            NaveIndex++;
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("NAVE NO ITERADA EN SU INDICE: %d"), NaveIndex));
            }
        }
        NaveIteratorInstance->Next();
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("ITERACION COMPLETADA."));
    }












































    ////************************************  FACADE    *********************************************
    FacadeNaves = GetWorld()->SpawnActor<AFacadeNaves>(AFacadeNaves::StaticClass());

    //FacadeNaves->SPAWN_NAVES_ENEMIGAS();
    FacadeNaves->SpawnPowerUpVelocidad();
    ////************************************  OBSERVER    *********************************************
    //FVector ubicacionReloj = FVector(-1160.0f, -1220.0f, 150.0f);
    //FVector ubicacionTorreEifel = FVector(-1200.0f, 1180.0f, 600.0f);
    //FRotator rotacionReloj = FRotator(0.0f, 0.0f, 0.0f);
    //FRotator rotacionTorreEifel = FRotator(60.0f, -40.0f, 0.0f);

    //Reloj = GetWorld()->SpawnActor<AReloj>(ubicacionReloj, rotacionReloj);
    //TorreEifel = GetWorld()->SpawnActor<ATorreEifel>(ubicacionTorreEifel, rotacionTorreEifel);

    //Publicador = GetWorld()->SpawnActor<APublicador>(APublicador::StaticClass());
    //TorreEifel->SetPublicador(Publicador);
    //Publicador->SubscriptorReloj(Reloj); 

    ////******************************************   STATE    *************************************************
    //FVector ubicacionNaveEstado = FVector(-1570.0f, 0.0f, 200.0f);
    //FRotator rotacionNaveEstado = FRotator(0.0f, 0.0f, 0.0f);

    //NaveEstado = GetWorld()->SpawnActor<ANaveEstado>(ubicacionNaveEstado, rotacionNaveEstado);

    ////*******************************************  STRATERGY  ***********************************************

    //UE_LOG(LogTemp, Warning, TEXT("Begin called"));


    //FVector ubicacionE = FVector(1600.0f, -900.0f, 850.0f);
    //FRotator rotacionE = FRotator(0.0f, 180.0f, 0.0f); 

    //// NAVE PADRIZA EXISTE
    //Estrategica = GetWorld()->SpawnActor<ANaveEstrategica>(ubicacionE, rotacionE);

    ////ESTRATEGIAS LAS INSTANCIAMOS
    //E_Espiadora = GetWorld()->SpawnActor<AEstrategiaEspiadora>(AEstrategiaEspiadora::StaticClass());
    //E_Ayudante = GetWorld()->SpawnActor<AEstrategiaAyudante>(AEstrategiaAyudante::StaticClass());
    //E_Disparadora = GetWorld()->SpawnActor<AEstrategiaDisparadora>(AEstrategiaDisparadora::StaticClass());

    //GetWorldTimerManager().SetTimer(TimerHandle_Reloj, this, &AGalaga_USFX_LAB02GameMode::TickReloj, 1.0f, true);




}


void AGalaga_USFX_LAB02GameMode::TickReloj()
{
    //E_Reloj += 1;

    //if (GEngine)
    //{
    //    GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("RELOJ PADRIZA MARCA: %d"), E_Reloj));
    //}

    //// Agrega aquí la lógica para cambiar las estrategias basándote en el valor de E_Reloj
    //if (!bEstrategiasCambiadas)
    //{
    //    if (E_Reloj <= 5.0)
    //    {
    //        Estrategica->AlterarEstrategia(E_Espiadora);
    //        Estrategica->EmplearEstrategia(DeltaTime);
    //    }
    //    if (E_Reloj > 5.0 && E_Reloj < 15.0)
    //    {
    //        Estrategica->AlterarEstrategia(E_Ayudante);
    //        Estrategica->EmplearEstrategia(DeltaTime);
    //    }
    //    if (E_Reloj > 15.0 && E_Reloj < 25.0)
    //    {
    //        Estrategica->AlterarEstrategia(E_Disparadora);
    //        Estrategica->EmplearEstrategia(DeltaTime);

    //    }
    //    if (E_Reloj >= 25.0)
    //    {
    //        E_Reloj = 0.0;
    //        bEstrategiasCambiadas = true; // Marcamos que las estrategias ya han sido cambiadas
    //    }
    //}
}




