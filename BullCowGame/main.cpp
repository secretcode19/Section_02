#include <iostream>

using namespace std;

// the entry point for our application
int main()
{
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";

	return 0;	// exit the application
}