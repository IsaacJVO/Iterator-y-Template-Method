// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef GALAGA_USFX_LAB02_ProyectilNodriza_generated_h
#error "ProyectilNodriza.generated.h already included, missing '#pragma once' in ProyectilNodriza.h"
#endif
#define GALAGA_USFX_LAB02_ProyectilNodriza_generated_h

#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_SPARSE_DATA
#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProyectilNodriza(); \
	friend struct Z_Construct_UClass_AProyectilNodriza_Statics; \
public: \
	DECLARE_CLASS(AProyectilNodriza, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Galaga_USFX_LAB02"), NO_API) \
	DECLARE_SERIALIZER(AProyectilNodriza)


#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAProyectilNodriza(); \
	friend struct Z_Construct_UClass_AProyectilNodriza_Statics; \
public: \
	DECLARE_CLASS(AProyectilNodriza, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Galaga_USFX_LAB02"), NO_API) \
	DECLARE_SERIALIZER(AProyectilNodriza)


#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProyectilNodriza(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProyectilNodriza) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProyectilNodriza); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProyectilNodriza); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProyectilNodriza(AProyectilNodriza&&); \
	NO_API AProyectilNodriza(const AProyectilNodriza&); \
public:


#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProyectilNodriza(AProyectilNodriza&&); \
	NO_API AProyectilNodriza(const AProyectilNodriza&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProyectilNodriza); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProyectilNodriza); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProyectilNodriza)


#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_PRIVATE_PROPERTY_OFFSET
#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_10_PROLOG
#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_PRIVATE_PROPERTY_OFFSET \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_SPARSE_DATA \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_RPC_WRAPPERS \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_INCLASS \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_PRIVATE_PROPERTY_OFFSET \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_SPARSE_DATA \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_INCLASS_NO_PURE_DECLS \
	Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GALAGA_USFX_LAB02_API UClass* StaticClass<class AProyectilNodriza>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Galaga_USFX_LAB02_Source_Galaga_USFX_LAB02_ProyectilNodriza_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
