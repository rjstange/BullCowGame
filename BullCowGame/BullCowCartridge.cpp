// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    // Welcome message
    PrintLine(TEXT("Welcome to Bull Cows."));
    PrintLine(TEXT("Are you smarter than these cows?"));
    PrintLine(TEXT("Enter the 5 letter word.")); // Magic Number Remove!
    PrintLine(TEXT("And then press enter..."));
    
    // Set HiddenWord from a list of possible words
    HiddenWord = "bugle"; 

    // Set lives == the length of the HiddenWord string.
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    // Convert input to lowercase
    // Check if input has no repeating characters
        // If input has repeating characters, guess again
    // Check Right Amount of Characters
        // If wrong amount, guess again
    
    // If Correct
        // Display Win message
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Correct! You win!"));
    }
    // If Lives is == 0, 
        // Game Over
        // Reveal HiddenWord

    // If lives > 0 
        // Reveal Remaining Lives
        // Ask Again.
    else
    {
        PrintLine(TEXT("Sorry, that is incorrect!")); 
        PrintLine(TEXT("Game over!")); 
    }

    // After win or lose:
    // Ask player if they want to play again
    // If Yes, go back to BeginPlay
    // If No, Quit
}