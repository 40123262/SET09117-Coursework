#pragma once
#include <iostream>
enum Colour 
{
	Black,
	White,
	BlackQueen,
	WhiteQueen,
	Empty,
	blank
};


class Checker
{
public:
	
	Checker();
	Checker(Colour c, char column, char row);
	~Checker();
	///set and get functions
	void SetPosition(char column, int row);
	char GetRow() {return row; };
	char GetCol() { return column; };
	void SetColour(Colour col) { colour = col; }
	
	Colour GetColour() { return colour; }


private:
	Colour colour;
	char column;
	char row;


};
