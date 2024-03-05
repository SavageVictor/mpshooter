// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Player count: %d"), NumberOfPlayers));
	if(NumberOfPlayers == 2)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Player count is good enough")));
		UWorld* World = GetWorld();
		if(World)
		{
			bUseSeamlessTravel = true;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Transfer")));
			World->ServerTravel(FString("/Game/Maps/TPShooterMap?listen"));
		}
	}
}
