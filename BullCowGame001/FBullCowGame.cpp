#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 4;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "ape";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; // TODO make actual error
}

// recieves a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount FBullCowCount;

	// loop through all letters in the guess
	int32 MyHiddenWordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < MyHiddenWordLength; MHWChar++)
	{
		// compare letters against the hidden 
		for (int32 GChar = 0; GChar < MyHiddenWordLength; GChar++)
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

	return FBullCowCount;
}
