#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"



UCLASS(Abstract) // Para que herede con el polimorfismo, metodos
class GALAGA_USFX_LAB02_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))

	UStaticMeshComponent* mallaNaveEnemiga;

public:

	ANaveEnemiga();

protected:
	virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

	virtual void Mover(float DeltaTime);
	virtual void Disparar();

    void TemplateMethod(float DeltaTime);
};