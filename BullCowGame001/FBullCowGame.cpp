#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "Dragon";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// recieves a VALID guess, incriments turn, and returns count
BullCowCount FBullCowGame::SubmitValidGuess(FString)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;

	// loop through all letters in the guess
		// compare letters against the hidden word


	return BullCowCount;
}
