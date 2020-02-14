#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
std::string GetGuess();
void PlayGame();
bool PlayAgain();
std::string Guess = "";

// The entry point of our application
int main() 
{
	do {
		PrintIntro();
		PlayGame();
	} while (PlayAgain());

	return 0; // exit application
}

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBERS_OF_TURNS = 5;
	for (int count = 1; count <= NUMBERS_OF_TURNS; count++)
	{
		GetGuess();
		// repeat the guess back to them
		std::cout << "Your guess was: " << Guess << std::endl;
	}

}

bool PlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');

}

std::string GetGuess()
{
	// Get a guess from the player
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;

}


void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Hello World!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n" << std::endl;
}
