// This is a console executable, that makes use of the Bull Cow Class.
// This acts as the view in a MVC pattern, and is responsible for all user interaction.
// For game logic see FBullCowGame class.

#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
Ftext GetGuess();
void PlayGame();
bool PlayAgain();

using FText = std::string;
using int32 = int;

FBullCowGame BCGame; // Instantiate a new state

// The entry point of our application
int32 main() 
{
	do {
		PrintIntro();
		PlayGame();
	} while (PlayAgain());

	return 0; // exit application
}

void PlayGame()
{
	BCGame.Reset();
	const int32 MaxTries = BCGame.GetMaxTries();
	int32 CurrentTry = BCGame.GetCurrentTry();

	// loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();
		// repeat the guess back to them
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	std::cout << "You beat the game with " << MaxTries - CurrentTry << " left!\n" << std::endl;
}

bool PlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');

}

std::FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// Get a guess from the player
	// TODO Validate Guess
	std::cout << "This is try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;

}


void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Hello World!\n" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n" << std::endl;

	// TODO make intro ASC
}
