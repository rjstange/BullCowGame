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
    else
    {
        CheckGuess(Input);
    }
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

    const TCHAR HW[] = TEXT("cakes");
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    ClearScreen();
    if (Lives == 0)
    {
        PrintLine(TEXT("You have no more lives!"));
        PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
        PrintLine(TEXT("Game over!"));
    }
    else
    {
        PrintLine(TEXT("Correct! You win!"));
    }
    
    PrintLine(TEXT("Press Enter to Play again..."));
}

void UBullCowCartridge::CheckGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        EndGame();
        return;
    }

    // Check Right Amount of Characters
    if (Guess.Len() != HiddenWord.Len()) // If wrong amount, guess again
    {
        PrintLine(TEXT("The hidden word is %i letters long\nTry again!"), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives remaining."), Lives);
        return;
    }

    // Check if input has repeating characters
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("Entry contains repeating characters\nTry again!"));
        return;
    }
    
    // Lose a life
    PrintLine(TEXT("Incorrect! You lost a life!\n%i more remaining!"), --Lives);
    PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
    
    if (Lives == 0) 
    {
        EndGame();
        return;
    }
}

bool UBullCowCartridge::IsIsogram(FString Word)
{
    /* Loop over each character in Word, 
    terminating early if the next character is the same */
    return true;
}