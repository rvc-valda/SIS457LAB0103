// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ejercicio3GameMode.h"
#include "Ejercicio3PlayerController.h"
#include "Ejercicio3Pawn.h"

AEjercicio3GameMode::AEjercicio3GameMode()
{
	// no pawn by default
	DefaultPawnClass = AEjercicio3Pawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AEjercicio3PlayerController::StaticClass();
}
