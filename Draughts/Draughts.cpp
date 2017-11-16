#include "stdafx.h"
#include <iostream>

#include "Checker.h"
#include "Board.h"
#include "Player.cpp"
#include <Windows.h>


std::ostream& operator<<(std::ostream& lhs, Colour e) {
	switch (e) {
	case 0: lhs << "Black"; break;
	case 1: lhs << "White"; break;
	case 2: lhs << "BlackQueen"; break;
	case 3: lhs << "WhiteQueen"; break;
	case 4: lhs << "Empty"; break;
	}
	return lhs;
}
static bool GameOver = false;

int main()
{
	Board* gameBoard = Board::getInstance();
	std::cout << "Choose game mode:\n0.Player vs Player\n1.Player vs PC\n2.PC vs PC";
	int mode;
	std::cin >> mode;
	Player one, two;
	switch (mode)
	{
	case 0:
		one = Player(White, 1, false);
		two = Player(Black, 2, false);
		break;
	case 1:
		one = Player(White, 1, false);
		two = Player(Black, 2, true);
		break;
	case 2:
		one = Player(White, 1, true);
		two = Player(Black, 2, true);
		break;
	}
	
	Player* current;
	current = &one;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	while (!GameOver)
	{
		
		if (one.isAI()) std::cout << "(AI) ";
		std::cout << "Player 1 (" << one.GetColour() << "): " << one.GetScore() << std::endl;
		if (two.isAI()) std::cout << "(AI) ";
		std::cout << "Player 2 (" << two.GetColour() << "): " << two.GetScore() << std::endl;
		char from_column='a', to_column='a';
		int from_row=0, to_row=0;
		gameBoard->Draw();
		if (current->GetScore() > 11)
		{
			GameOver = true;
			std::cout << "\n\nPlayer " << current->GetIndex() << " wins!!!!\n\n";
			break;
		}
	if(!current->isAI())
		{
			std::cout << std::endl << "Player " << current->GetIndex() << " (" << current->GetColour() << "): Select a checker to move. (ColumnRow)";
			std::cin >> from_column >> from_row;
			if (gameBoard->FieldColour(from_column, from_row) != current->GetColour() && gameBoard->FieldColour(from_column, from_row) != current->GetQueenColour())
			{
				system("cls");
				SetConsoleTextAttribute(h, 199);
				std::cout << std::endl << "Player " << current->GetIndex() << " can only move " << current->GetColour() << " checkers.\n";
				SetConsoleTextAttribute(h, 15);
				continue;
			}
			std::cout << std::endl << "Select destination. (ColumnRow)";
			std::cin >> to_column >> to_row;
		
			current->Move(toupper(from_column), from_row, toupper(to_column), to_row);
		}
		else
			current->AIMove();
	
		if(current->MoveDone())
		current = (current == &one) ? &two : &one;
 		system("cls");
	}
	char c;
	std::cin >> c;
}




