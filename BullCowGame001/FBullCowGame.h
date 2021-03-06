/*  
	The game logic (No view code or direct user interaction)
	The game is a simple guess the word game based on Mastermind
*/

#pragma once
#include <string>

// To make syntax Unreal friendly
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

	void Reset(); 
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const; 
	int32 GetHiddenWordLength() const; 
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; 
	// provide a method for counting Bulls & Cows, increasing turn #
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;
};