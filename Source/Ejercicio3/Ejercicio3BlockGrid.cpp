// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ejercicio3BlockGrid.h"
#include "Ejercicio3Block.h"
#include "Components/TextRenderComponent.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AEjercicio3BlockGrid::AEjercicio3BlockGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);

	BiografiaText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("BiografiaText0"));
	BiografiaText->SetRelativeLocation(FVector(350.f, 0.f, 0.f));
	BiografiaText->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	BiografiaText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Bigrafia, Mi nombre es Rodrigo Valda Corchado, tengo 21 años en mi familia me conocen como roro o rodri y estudio la carrera de ing. sistemas: {0}"), FText::AsNumber(0)));
	BiografiaText->SetupAttachment(DummyRoot);

	// Set defaults
	Size = 3;
	BlockSpacing = 300.f;
}


void AEjercicio3BlockGrid::BeginPlay()
{
	Super::BeginPlay();

	// Number of blocks
	const int32 NumBlocks = Size * Size;

	// Loop to spawn each block
	for(int32 BlockIndex=0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex/Size) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex%Size) * BlockSpacing; // Modulo gives remainder

		// Make position vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		AEjercicio3Block* NewBlock = GetWorld()->SpawnActor<AEjercicio3Block>(BlockLocation, FRotator(0,0,0));

		// Tell the block about its owner
		if (NewBlock != nullptr)
		{
			NewBlock->OwningGrid = this;
		}
	}
}


void AEjercicio3BlockGrid::AddScore()
{
	// Increment score
	Score++;

	// Update text
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

#undef LOCTEXT_NAMESPACE
