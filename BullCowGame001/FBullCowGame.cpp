#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // default Constructor 

int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WorldLengthMaxTries{ {3, 5}, {4, 6}, {5, 10}, {6, 16}, {7, 20}, {8, 24} };
	return WorldLengthMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	bGameIsWon = false;
	const FString HIDDEN_WORD = "ape";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // if the guess is not all lowercase
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letters as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup map
	for (auto Letter : Word) // for all the letters of the word
	{
		for (int Letter = 0; Letter < Word.length(); Letter++)
		{
			Letter = tolower(Letter); // handle mixed case
			if (LetterSeen[Letter])
			{
				return false;
			}
			else
			{
				LetterSeen[Letter] = true;
			}
		}
	}
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}
