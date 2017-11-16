#include <iostream>
#include "stdafx.h"
#include "Board.h"
#include "Checker.h"
#include <Windows.h>


Board* Board::instance;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum Columns { A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7 };

Board::Board()
{
	ResetBoard();
}
Board* Board::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Board();
	}
	return instance;
}
Colour Board::FieldColour(char col, char row)
{
	if (row - 1 < 0 || row-1 > 7 || (toupper(col) - 65) < 0 || (toupper(col) - 65)>7)
		return blank;
	return currentState[toupper(col) - 65][row - 1].GetColour();

}
bool Board::CanBeKilled(char col, char row, Colour colour)
{
	Colour enemy, enemyQueen;
	if (colour == Black)
	{
		enemy = White;
		enemyQueen = WhiteQueen;
	}
	else
	{
		enemy = Black;
		enemyQueen = BlackQueen;
	}
	if ((FieldColour(col - 1, row - 1) == Empty) && ((FieldColour(col + 1, row + 1) == enemy)|| (FieldColour(col + 1, row + 1) == enemyQueen)))
		return true;
	if ((FieldColour(col + 1, row - 1) == Empty) && ((FieldColour(col - 1, row + 1) == enemy) || (FieldColour(col + 1, row + 1) == enemyQueen)))
		return true;
	if ((FieldColour(col + 1, row + 1) == Empty) && (FieldColour(col - 1, row - 1) == enemy) || ((FieldColour(col + 1, row + 1) == enemyQueen)))
		return true;
	if ((FieldColour(col - 1, row + 1) == Empty) && (FieldColour(col + 1, row - 1) == enemy) || ((FieldColour(col + 1, row + 1) == enemyQueen)))
		return true;
	return false;
}
bool Board::CanMove(char col, char row)
{
	if (currentState[toupper(col) - 65][row - 1].GetColour() == White)
		if (FieldColour(col - 1, row - 1) == Empty || FieldColour(col - +1, row - 1) == Empty)
			return true;
	if (currentState[toupper(col) - 65][row - 1].GetColour() == Black)
		if (FieldColour(col - 1, row + 1) == Empty || FieldColour(col - +1, row + 1) == Empty)
			return true;
	if (currentState[toupper(col) - 65][row - 1].GetColour() == BlackQueen || currentState[toupper(col) - 65][row - 1].GetColour() == WhiteQueen)
		if (FieldColour(col - 1, row + 1) == Empty || FieldColour(col - +1, row + 1) == Empty || FieldColour(col - 1, row - 1) == Empty || FieldColour(col - +1, row - 1) == Empty)
			return true;
	return false;
}
bool Board::CanKill(char col, char row)
{
	if (FieldColour(col, row) == White || FieldColour(col, row) == WhiteQueen)
	{
		if ((FieldColour(col - 1, row - 1) == Black || FieldColour(col - 1, row - 1) == BlackQueen) && (FieldColour(col - 2, row - 2) == Empty))
			return true;
		if ((FieldColour(col + 1, row - 1) == Black || FieldColour(col + 1, row - 1) == BlackQueen) && (FieldColour(col + 2, row - 2) == Empty))
			return true;
		if ((FieldColour(col + 1, row + 1) == Black || FieldColour(col + 1, row + 1) == BlackQueen) && (FieldColour(col + 2, row + 2) == Empty))
			return true;
		if ((FieldColour(col - 1, row + 1) == Black || FieldColour(col - 1, row + 1) == BlackQueen) && (FieldColour(col - 2, row + 2) == Empty))
			return true;
	} 
	if (FieldColour(col, row) == Black || FieldColour(col, row) == BlackQueen)
	{
		if ((FieldColour(col - 1, row - 1) == White || FieldColour(col - 1, row - 1) == WhiteQueen) && (FieldColour(col - 2, row - 2) == Empty))
			return true;
		if ((FieldColour(col + 1, row - 1) == White || FieldColour(col + 1, row - 1) == WhiteQueen) && (FieldColour(col + 2, row - 2) == Empty))
			return true;
		if ((FieldColour(col + 1, row + 1) == White || FieldColour(col + 1, row + 1) == WhiteQueen) && (FieldColour(col + 2, row + 2) == Empty))
			return true;
		if ((FieldColour(col - 1, row + 1) == White || FieldColour(col - 1, row + 1) == WhiteQueen) && (FieldColour(col - 2, row + 2) == Empty))
			return true;
	}
	return false;
}
void Board::ResetBoard()
{
	currentState[A][0] = Checker(Empty);
	currentState[B][0] = Checker(Black);
	currentState[C][0] = Checker(Empty);
	currentState[D][0] = Checker(Black);
	currentState[E][0] = Checker(Empty);
	currentState[F][0] = Checker(Black);
	currentState[G][0] = Checker(Empty);
	currentState[H][0] = Checker(Black);

	currentState[A][1] = Checker(Black);
	currentState[B][1] = Checker(Empty);
	currentState[C][1] = Checker(Black);
	currentState[D][1] = Checker(Empty);
	currentState[E][1] = Checker(Black);
	currentState[F][1] = Checker(Empty);
	currentState[G][1] = Checker(Black);
	currentState[H][1] = Checker(Empty);

	currentState[A][2] = Checker(Empty);
	currentState[B][2] = Checker(Black);
	currentState[C][2] = Checker(Empty);
	currentState[D][2] = Checker(Black);
	currentState[E][2] = Checker(Empty);
	currentState[F][2] = Checker(Black);
	currentState[G][2] = Checker(Empty);
	currentState[H][2] = Checker(Black);

	currentState[A][3] = Checker(Empty);
	currentState[B][3] = Checker(Empty);
	currentState[C][3] = Checker(Empty);
	currentState[D][3] = Checker(Empty);
	currentState[E][3] = Checker(Empty);
	currentState[F][3] = Checker(Empty);
	currentState[G][3] = Checker(Empty);
	currentState[H][3] = Checker(Empty);

	currentState[A][4] = Checker(Empty);
	currentState[B][4] = Checker(Empty);
	currentState[C][4] = Checker(Empty);
	currentState[D][4] = Checker(Empty);
	currentState[E][4] = Checker(Empty);
	currentState[F][4] = Checker(Empty);
	currentState[G][4] = Checker(Empty);
	currentState[H][4] = Checker(Empty);

	currentState[A][5] = Checker(White);
	currentState[B][5] = Checker(Empty);
	currentState[C][5] = Checker(White);
	currentState[D][5] = Checker(Empty);
	currentState[E][5] = Checker(White);
	currentState[F][5] = Checker(Empty);
	currentState[G][5] = Checker(White);
	currentState[H][5] = Checker(Empty);

	currentState[A][6] = Checker(Empty);
	currentState[B][6] = Checker(White);
	currentState[C][6] = Checker(Empty);
	currentState[D][6] = Checker(White);
	currentState[E][6] = Checker(Empty);
	currentState[F][6] = Checker(White);
	currentState[G][6] = Checker(Empty);
	currentState[H][6] = Checker(White);

	currentState[A][7] = Checker(White);
	currentState[B][7] = Checker(Empty);
	currentState[C][7] = Checker(White);
	currentState[D][7] = Checker(Empty);
	currentState[E][7] = Checker(White);
	currentState[F][7] = Checker(Empty);
	currentState[G][7] = Checker(White);
	currentState[H][7] = Checker(Empty);
}
bool Board::IsFieldEmpty(char col, char row) 
{
	if (currentState[toupper(col)-65 ][row - 1].GetColour() == Empty)
		return true;
	else
		return false;
}
void Board::Draw()
{	
	for (int i = 0; i < 8; i++)
	{
		if (FieldColour(i + 65, 1) == White)
			currentState[i][0] = Checker(WhiteQueen);
		if (FieldColour(i + 65, 8) == Black)
			currentState[i][7] = Checker(BlackQueen);
	}
	int k = 240;
	SetConsoleTextAttribute(hConsole, 15);
	std::wcout << "     A | B | C | D | E | F | G | H |"<< std::endl;
	for (int i = 0; i < 8; i++)
	{
		
		std::cout << std::endl << i + 1 << ".";
		k = (k == 240) ? 128 : 240;
		std::cout<<" |";
		for (int j = 0; j < 8; j++)
		{
			k = (k == 240) ? 128 : 240;
			SetConsoleTextAttribute(hConsole, k);
			if (currentState[j][i].GetColour() == White)
				std::cout << " O |";
			if (currentState[j][i].GetColour() == WhiteQueen)
				std::cout << "(O)|";
			if (currentState[j][i].GetColour() == Black)
				std::cout << " # |";
			if (currentState[j][i].GetColour() == BlackQueen)
				std::cout << "(#)|";
			if (currentState[j][i].GetColour() == Empty)
				std::cout << "   |";
		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << std::endl << "                                   ";
	}
}