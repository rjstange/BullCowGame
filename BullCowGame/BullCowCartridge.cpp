// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows."));
    PrintLine(TEXT("Are you smarter than these cows?"));
    PrintLine(TEXT("Guess the 5 letter word.")); // Magic Number Remove!
    PrintLine(TEXT("Press enter to begin..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("bugle"); // Move outside of the function later.
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Correct! You win!"));
    }
    else
    {
        PrintLine(TEXT("Sorry, that is incorrect!"));
        PrintLine(TEXT("Game over!"));
    }
    
    PrintLine(Input);
}