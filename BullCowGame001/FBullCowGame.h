#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_Lowercase,
	Wrong_Length
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	void Reset(); // TODO make a more rich return value
	int32 GetMaxTries() const; // Get max tries
	int32 GetCurrentTry() const; // Get current try?
	int32 GetHiddenWordLength() const; // Get Hidden Word Length

	bool IsGameWon() const; // Is the game over?
	EGuessStatus CheckGuessValidity(FString) const; // Does guess match correct answer and TODO make a more rich return value
	// provide a method for counting Bulls & Cows, increasing turn #
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString Word) const;
};