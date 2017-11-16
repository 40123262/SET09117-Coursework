#pragma once
#include "Checker.h"
#include <iostream>
#include <vector>
class Board
{

public:

//	~Board();
	static Board* getInstance();
	bool IsFieldEmpty(char col, char row);
	Colour FieldColour(char col, char row);
	void ResetBoard();
	void Draw();
	bool CanBeKilled(char col, char row, Colour colour);
	bool CanMove(char col, char row);
	bool CanKill(char col, char row);
	Checker currentState[8][8];
private:
	Board();
	static Board* instance;
};