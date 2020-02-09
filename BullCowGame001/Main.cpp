#include <iostream>
#include <string>


int main() 
{
	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Hello World!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n" << std::endl;

	// Get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	// repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl;

	return 0;
}