#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	void Reset(); // TODO make a more rich return value
	int GetMaxTries() const; // Get max tries
	int GetCurrentTry() const; // Get current try?
	bool IsGameWon() const; // Is the game over?
	bool CheckGuessValidity(std::string); // Does guess match correct answer and TODO make a more rich return value

private:
	int MyCurrentTry;
	int MyMaxTries;
};