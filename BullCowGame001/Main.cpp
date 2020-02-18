// This is a console executable, that makes use of the Bull Cow Class.
// This acts as the view in a MVC pattern, and is responsible for all user interaction.
// For game logic see FBullCowGame class.

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // Instantiate a new state

// The entry point of our application
int32 main() 
{ 
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // exit application
}

void PlayGame()
{
	BCGame.Reset();
	const int32 MaxTries = BCGame.GetMaxTries();
	int32 CurrentTry = BCGame.GetCurrentTry();

	// loop for the number of turns asking for guesses
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(); // Check for Guess

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls equals = " << BullCowCount.Bulls ;
		std::cout << ". Cows equals = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}

	PrintGameSummary();
}

// loop until the user gives a valid guess
	FText GetValidGuess() 
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "This is try " << CurrentTry << ". Enter your guess: ";

		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Try again! Your guess cannot have repeating letters!\n" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Try again! Your guess can only be lowercase letters!\n" << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Try again! Your guess has to be " << BCGame.GetHiddenWordLength() << " characters long!\n" << std::endl;
			break;
		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}


void PrintIntro()
{
	const int32 WordLength = BCGame.GetHiddenWordLength();
	std::cout << "Hello World!\n" << std::endl;
	std::cout << "Can you guess the " << WordLength << " letter isogram?\n" << std::endl;

	// TODO make intro ASC11
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');

}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "You won!! Now play again or quit! \n" << std::endl;
	}
	else
	{
		std::cout << "You lost! Better luck next time! \n" << std::endl;
	}
}