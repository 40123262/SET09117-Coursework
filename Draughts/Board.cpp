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
	currentState[A][0] = Checker(Empty, A, 1);
	currentState[B][0] = Checker(Black, B, 1);
	currentState[C][0] = Checker(Empty, C, 1);
	currentState[D][0] = Checker(Black, D, 1);
	currentState[E][0] = Checker(Empty, E, 1);
	currentState[F][0] = Checker(Black, F, 1);
	currentState[G][0] = Checker(Empty, G, 1);
	currentState[H][0] = Checker(Black, H, 1);

	currentState[A][1] = Checker(Black, A, 2);
	currentState[B][1] = Checker(Empty, B, 2);
	currentState[C][1] = Checker(Black, C, 2);
	currentState[D][1] = Checker(Empty, D, 2);
	currentState[E][1] = Checker(Black, E, 2);
	currentState[F][1] = Checker(Empty, F, 2);
	currentState[G][1] = Checker(Black, G, 2);
	currentState[H][1] = Checker(Empty, H, 2);

	currentState[A][2] = Checker(Empty, A, 3);
	currentState[B][2] = Checker(Black, B, 3);
	currentState[C][2] = Checker(Empty, C, 3);
	currentState[D][2] = Checker(Black, D, 3);
	currentState[E][2] = Checker(Empty, E, 3);
	currentState[F][2] = Checker(Black, F, 3);
	currentState[G][2] = Checker(Empty, G, 3);
	currentState[H][2] = Checker(Black, H, 3);

	currentState[A][3] = Checker(Empty, A, 4);
	currentState[B][3] = Checker(Empty, B, 4);
	currentState[C][3] = Checker(Empty, C, 4);
	currentState[D][3] = Checker(Empty, D, 4);
	currentState[E][3] = Checker(Empty, E, 4);
	currentState[F][3] = Checker(Empty, F, 4);
	currentState[G][3] = Checker(Empty, G, 4);
	currentState[H][3] = Checker(Empty, H, 4);

	currentState[A][4] = Checker(Empty, A, 5);
	currentState[B][4] = Checker(Empty, B, 5);
	currentState[C][4] = Checker(Empty, C, 5);
	currentState[D][4] = Checker(Empty, D, 5);
	currentState[E][4] = Checker(Empty, E, 5);
	currentState[F][4] = Checker(Empty, F, 5);
	currentState[G][4] = Checker(Empty, G, 5);
	currentState[H][4] = Checker(Empty, H, 5);

	currentState[A][5] = Checker(White, A, 6);
	currentState[B][5] = Checker(Empty, B, 6);
	currentState[C][5] = Checker(White, C, 6);
	currentState[D][5] = Checker(Empty, D, 6);
	currentState[E][5] = Checker(White, E, 6);
	currentState[F][5] = Checker(Empty, F, 6);
	currentState[G][5] = Checker(White, G, 6);
	currentState[H][5] = Checker(Empty, H, 6);

	currentState[A][6] = Checker(Empty, A, 7);
	currentState[B][6] = Checker(White, B, 7);
	currentState[C][6] = Checker(Empty, C, 7);
	currentState[D][6] = Checker(White, D, 7);
	currentState[E][6] = Checker(Empty, E, 7);
	currentState[F][6] = Checker(White, F, 7);
	currentState[G][6] = Checker(Empty, G, 7);
	currentState[H][6] = Checker(White, H, 7);

	currentState[A][7] = Checker(White, A, 8);
	currentState[B][7] = Checker(Empty, B, 8);
	currentState[C][7] = Checker(White, C, 8);
	currentState[D][7] = Checker(Empty, D, 8);
	currentState[E][7] = Checker(White, E, 8);
	currentState[F][7] = Checker(Empty, F, 8);
	currentState[G][7] = Checker(White, G, 8);
	currentState[H][7] = Checker(Empty, H, 8);
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
			currentState[i][0] = Checker(WhiteQueen, (char)(i + 65), 1);
		if (FieldColour(i + 65, 8) == Black)
			currentState[i][7] = Checker(BlackQueen, (char)(i + 65), 8);
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