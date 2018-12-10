#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// the entry point for our application
int main()
{
	PrintIntro();

	GetGuessAndPrintBack();
	GetGuessAndPrintBack();

	cout << endl;
	return 0;	// exit the application
}

void PrintIntro()
{
	// introduce the game
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?";
	cout << endl;
	return;
}

string GetGuessAndPrintBack()
{
	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}