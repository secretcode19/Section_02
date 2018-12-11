#pragma once
#include <string>

using namespace std;

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	// TODO make a more rich return value.
	bool CheckGuessValidity(std::string);	// TODO make a more rich return value.

// Please try and ignore this and focus on the interface above
private:
	// see constructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;
};