#pragma once
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
	Checker(Colour c);
	void SetColour(Colour col) { colour = col; }	
	Colour GetColour() { return colour; }


private:
	Colour colour;
};
