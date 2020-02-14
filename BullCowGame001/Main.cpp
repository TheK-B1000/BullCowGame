#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
std::string GetGuess();
void PlayGame();
bool PlayAgain();

FBullCowGame BCGame; // Instantiate a new state

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
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		// repeat the guess back to them
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

}

bool PlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	std::cout << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');

}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	// Get a guess from the player
	std::cout << "This is try " << CurrentTry << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;

}


void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Hello World!\n" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n" << std::endl;
}
