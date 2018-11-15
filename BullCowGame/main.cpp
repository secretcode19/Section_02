#include <iostream>
#include "FBullCowGame.h"

using FText = string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		// TODO game summary
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;	// exit the application
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns for guess
	for (int32 count = 1; count <= MaxTries; count++)
	{
		// get a guess from the player
		FText Guess = GetGuess();	// TODO make loop checking valid

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// Submit valid guess to the game, and receive counts
		BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows
		cout << "Bulls = " << BullCowCount.Bulls;
		cout << ". Cows = " << BullCowCount.Cows << endl;

		cout << endl;
	}

	// TODO summarise game
}

// introduce the game
void PrintIntro()
{
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	cout << " letter isogram I'm thinking of?";
	cout << endl;
	return;
}

// get a guess from the player
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	cout << "Try :" << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again y/n? ";
	FText Response = "";

	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
