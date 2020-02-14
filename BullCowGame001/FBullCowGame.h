#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(); // TODO make a more rich return value
	int GetMaxTries(); // Get max tries
	int GetCurrentTry(); // Get current try?
	bool IsGameWon(); // Is the game over?
	bool CheckGuessValidity(std::string); // Does guess match correct answer and TODO make a more rich return value

private:
	int MyCurrentTry;
	int MyMaxTries;
};