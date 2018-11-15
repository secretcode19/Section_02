#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "donkey";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)	// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)	// if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length != GetHiddenWordLength())	// if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else // otherwise
	{
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, incriments and returns count
BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for(int32 i = 0; i < HiddenWordLength; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// if they match then
			if (Guess[j] == MyHiddenWord[i]) {
				if (i == j) {	// if they're in the same place
					BullCowCount.Bulls++;	// incriment bulls
				}
				// else
				else {
					BullCowCount.Cows++;	// incriment cows
				}
			}
		}
	}
	return BullCowCount;
}
