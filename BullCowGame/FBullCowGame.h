#pragma once
#include <string>

using namespace std;

using FString = string;
using int32 = int;

// two values intiail default.
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame();	// constructor


	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;	// TODO make a more rich return value.

	void Reset();	// TODO make a more rich return value.

	// provide a method for counting bulls & cows, and increasing turn #
	// counts bulls & cows, and increases try # assuming valid guess
	BullCowCount SubmitGuess(FString);

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};