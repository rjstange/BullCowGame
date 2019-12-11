// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Check the player guess
    {
        // Check Right Amount of Characters
            // If wrong amount, guess again
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is %i letters long\nTry again!"), HiddenWord.Len());
        }
        // Check if input has no repeating characters
            // If input has repeating characters, guess again
        else
        {
            if (Input == HiddenWord)
            {
                PrintLine(TEXT("Correct! You win!"));
                EndGame();
            }
            else
            {    
                if (Lives > 0) 
                {
                    PrintLine(TEXT("Incorrect! You lost a life!\n%i more remaining!"), --Lives);
                }
                else
                {
                    PrintLine(TEXT("Sorry, that is incorrect!\nYou have no more lives!")); 
                    EndGame();
                }
            }
        }
    }
    // After win or lose:
    // Ask player if they want to play again
    // If Yes, go back to BeginPlay
    // If No, Quit
}

void UBullCowCartridge::SetupGame()
{
    bGameOver = false;
    HiddenWord = TEXT("cake");

    // Set lives == the length of the HiddenWord string.
    Lives = HiddenWord.Len(); 
    // bGameOver = false;
    PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *HiddenWord)); // Debug line
    
    // Welcome message
    PrintLine(TEXT("Welcome to Bull Cows."));
    PrintLine(TEXT("Are you smarter than these cows?"));
    PrintLine(FString::Printf(TEXT("Enter the %i letter word."), HiddenWord.Len()));
    PrintLine(TEXT("You have %i lives\nPress enter to continue..."), Lives);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Game over! Press Enter to Continue..."));
}