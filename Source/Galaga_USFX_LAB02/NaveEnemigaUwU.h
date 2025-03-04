
#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaUwU.generated.h"


UCLASS()

class GALAGA_USFX_LAB02_API ANaveEnemigaUwU : public ANaveEnemiga
{
	GENERATED_BODY()





public:
	ANaveEnemigaUwU();

	FString tipoUwU = "UwU";
public:
	virtual void BeginPlay() override;	


public:
	virtual void Mover(float DeltaTime) override;
	virtual void Disparar() override;

protected:
	float Radio = 1000.0f;
	float Angulo = 0.0f;
	float Speed = 10.0f;
};
