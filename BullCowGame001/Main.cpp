// This is a console executable, that makes use of the Bull Cow Class.
// This acts as the view in a MVC pattern, and is responsible for all user interaction.
// For game logic see FBullCowGame class.

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool PlayAgain();

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
		FText Guess = GetGuess(); // Check for Guess
		// Validate Guess
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls equals = " << BullCowCount.Bulls ;
		std::cout << ". Cows equals = " << BullCowCount.Cows << std::endl;


		std::cout << std::endl;
	}

	std::cout << "You beat the game with " << MaxTries - CurrentTry << " tries left!\n" << std::endl;
}

bool PlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');

}

	FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// Get a guess from the player

	std::cout << "This is try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;

}


void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 6;
	std::cout << "Hello World!\n" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n" << std::endl;

	// TODO make intro ASC
}
