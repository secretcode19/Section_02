#include <iostream>
#include <string>

using namespace std;

// the entry point for our application
int main()
{
	// introduce the game
	constexpr int WORLD_LENGTH = 9;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";

	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	cout << "Enter your guess: ";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	cout << endl;
	return 0;	// exit the application
}