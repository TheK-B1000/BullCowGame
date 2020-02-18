#include "FBullCowGame.h"
#include <iostream>

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 4;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	bGameIsWon = false;
	const FString HIDDEN_WORD = "ape";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess is not all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())// if the guess is not the right length
	{
		return EGuessStatus::Wrong_Length;

	}
	// otherwise
	else
	{
		return EGuessStatus::OK;
	}

}

// recieves a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount FBullCowCount;

	// loop through all letters in the HiddenWord
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) // TODO change from FOR to WHILE loop
	{
		// compare letters against the hidden 
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				//  if they're in the same place
				if (MHWChar == GChar)
				{
					// incriment bulls
					FBullCowCount.Bulls++;
				}
				else
				{
					// incriment cows if not
					FBullCowCount.Cows++;
				}
			}
		}
	}
	if (FBullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return FBullCowCount;
}
