#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	void Reset(); // TODO make a more rich return value
	int32 GetMaxTries() const; // Get max tries
	int32 GetCurrentTry() const; // Get current try?

	bool IsGameWon() const; // Is the game over?
	bool CheckGuessValidity(FString); // Does guess match correct answer and TODO make a more rich return value
	// provide a method for counting Bulls & Cows, increasing turn #
	BullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};