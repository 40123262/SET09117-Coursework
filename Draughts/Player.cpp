
#include "stdafx.h"
#include "Checker.h"
#include "Board.h"
#include <cmath>
#include <vector>
#include <algorithm> 
#include <cstdlib>
class Player
{
Board* gameBoard = Board::getInstance();

struct position
{
	int x;
	int y;
	position(char col, char row)
	{
		x = col; y = row;
	}
};

public:
	Player(){}
	virtual bool isAI() { return AI; }
	virtual Colour GetColour() { return colour; }
	virtual Colour GetQueenColour() { return queenC; }
	virtual int GetScore() { return score; }
	virtual int GetIndex() { return index; }
	virtual bool MoveDone() { return done; }
	virtual void Move(char from_col, int from_row, char to_col, int to_row)
	{

		done = false;
		if (gameBoard->FieldColour(from_col, from_row) == White)
		{
			if (!hasToKill && (!gameBoard->IsFieldEmpty(from_col, from_row) && gameBoard->IsFieldEmpty(to_col, to_row)) && abs(from_col - to_col) == 1 && (from_row - to_row) == 1)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(White);
				done = true;
			}
			else if ((!gameBoard->IsFieldEmpty(from_col, from_row) && ((gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == Black) || (gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == BlackQueen)) && gameBoard->IsFieldEmpty(to_col, to_row)) && std::abs(from_col - to_col) == 2 && std::abs(from_row - to_row) == 2)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(White);
				gameBoard->currentState[((from_col - 65) + (to_col - 65)) / 2][((from_row - 1) + (to_row - 1)) / 2] = Checker(Empty);
				score++;
				if (gameBoard->CanKill(to_col, to_row))
				{		
					hasToKill = true;
					done = false;
				}
				else
				{
					hasToKill = false;
					done = true;
				}
			}
			else
			{
				std::cout << "Illegal move!\n";
			}
		}
		else if (gameBoard->FieldColour(from_col, from_row) == Black)
		{
			if (!hasToKill &&(!gameBoard->IsFieldEmpty(from_col, from_row) && gameBoard->IsFieldEmpty(to_col, to_row)) && abs(from_col - to_col) == 1 && (to_row - from_row)  == 1)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(Black);
				done = true;
			}
			else if((!gameBoard->IsFieldEmpty(from_col, from_row) && ((gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == White) || (gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == WhiteQueen)) && gameBoard->IsFieldEmpty(to_col, to_row)) && std::abs(to_col - from_col) == 2 && std::abs(to_row - from_row) == 2)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(Black);
				gameBoard->currentState[((from_col - 65) + (to_col - 65)) / 2][((from_row - 1) + (to_row - 1)) / 2] = Checker(Empty);
				score++;
				if (gameBoard->CanKill(to_col, to_row))
				{
					hasToKill = true;
					done = false;
				}
				else
				{
					hasToKill = false;
					done = true;
				}
			}
			else
			{
				std::cout << "Illegal move!\n";
			}
		}
		else if (gameBoard->FieldColour(from_col, from_row) == WhiteQueen)
		{

			if (!hasToKill && !gameBoard->IsFieldEmpty(from_col, from_row) && gameBoard->IsFieldEmpty(to_col, to_row) && abs(to_col - from_col) == 1 && abs(from_row - to_row) == 1)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(WhiteQueen);
				done = true;
			}
			else if ((!gameBoard->IsFieldEmpty(from_col, from_row) && ((gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == Black) || (gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == BlackQueen)) && gameBoard->IsFieldEmpty(to_col, to_row)) && std::abs(from_col - to_col) == 2 && std::abs(from_row - to_row) == 2)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(WhiteQueen);
				gameBoard->currentState[((from_col - 65) + (to_col - 65)) / 2][((from_row - 1) + (to_row - 1)) / 2] = Checker(Empty);
				score++;
				if (gameBoard->CanKill(to_col, to_row))
				{
					hasToKill = true;
					done = false;
				}
				else
				{
					hasToKill = false;
					done = true;
				}
			}
			else
			{
				std::cout << "Illegal move!\n";
			}
		}
		else if (gameBoard->FieldColour(from_col, from_row) == BlackQueen)
		{
			if (!hasToKill && !gameBoard->IsFieldEmpty(from_col, from_row) && gameBoard->IsFieldEmpty(to_col, to_row) && abs(from_col - to_col) == 1 && abs(from_row - to_row) == 1)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(BlackQueen);
				done = true;
			}
			else if ((!gameBoard->IsFieldEmpty(from_col, from_row) && ((gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == White) || (gameBoard->FieldColour((from_col + to_col) / 2, (from_row + to_row) / 2) == WhiteQueen)) && gameBoard->IsFieldEmpty(to_col, to_row)) && std::abs(from_col - to_col) == 2 && std::abs(from_row - to_row) == 2)
			{
				gameBoard->currentState[from_col - 65][from_row - 1] = Checker(Empty);
				gameBoard->currentState[to_col - 65][to_row - 1] = Checker(BlackQueen);
				gameBoard->currentState[((from_col - 65) + (to_col - 65)) / 2][((from_row - 1) + (to_row - 1)) / 2] = Checker(Empty);
				score++;
				if (gameBoard->CanKill(to_col, to_row))
				{
					hasToKill = true;
					done = false;
				}
				else
				{
					hasToKill = false;
					done = true;
				}
			}
			else
			{
				std::cout << "Illegal move!\n";
			}
		}
		

	}
	
	void AIKill(char col, char row)
	{
		Colour enemy, enemyQueen;
		if (colour == Black)
		{
			enemy = White;
			enemyQueen = WhiteQueen;
		} else
		{
			enemy = Black;
			enemyQueen = BlackQueen;
		}
		if ((gameBoard->FieldColour(col - 1, row - 1) == enemy || gameBoard->FieldColour(col - 1, row - 1) == enemyQueen) && (gameBoard->FieldColour(col - 2, row - 2) == Empty))
		{
			gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
			gameBoard->currentState[col - 67][row - 3] = Checker(colour);
			gameBoard->currentState[((col - 65) + (col - 67)) / 2][((row - 1) + (row - 3)) / 2] = Checker(Empty);
			score++;
			if (gameBoard->CanKill(col-2, row-2))
			{
				hasToKill = true;
				done = false;
			}
			else
			{
				hasToKill = false;
				done = true;
			}
		}
		if ((gameBoard->FieldColour(col + 1, row - 1) == enemy || gameBoard->FieldColour(col + 1, row - 1) == enemyQueen) && (gameBoard->FieldColour(col + 2, row - 2) == Empty))
		{
			gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
			gameBoard->currentState[col - 63][row - 3] = Checker(colour);
			gameBoard->currentState[((col - 65) + (col - 63)) / 2][((row - 1) + (row - 3)) / 2] = Checker(Empty);
			score++;
			if (gameBoard->CanKill(col + 2, row - 2))
			{
				hasToKill = true;
				done = false;
			}
			else
			{
				hasToKill = false;
				done = true;
			}
		}
		if ((gameBoard->FieldColour(col + 1, row + 1) == enemy || gameBoard->FieldColour(col + 1, row + 1) == enemyQueen) && (gameBoard->FieldColour(col + 2, row + 2) == Empty))
		{
			gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
			gameBoard->currentState[col - 63][row + 1] = Checker(colour);
			gameBoard->currentState[((col - 65) + (col - 63)) / 2][((row - 1) + (row + 1)) / 2] = Checker(Empty);
			score++;
			if (gameBoard->CanKill(col + 2, row + 2))
			{
				hasToKill = true;
				done = false;
			}
			else
			{
				hasToKill = false;
				done = true;
			}
		}
		if ((gameBoard->FieldColour(col - 1, row + 1) == enemy || gameBoard->FieldColour(col - 1, row + 1) == enemyQueen) && (gameBoard->FieldColour(col - 2, row + 2) == Empty))
		{
			gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
			gameBoard->currentState[col - 67][row + 1] = Checker(colour);
			gameBoard->currentState[((col - 65) + (col - 67)) / 2][((row - 1) + (row + 1)) / 2] = Checker(Empty);
			score++;
			if (gameBoard->CanKill(col - 2, row + 2))
			{
				hasToKill = true;
				done = false;
			}
			else
			{
				hasToKill = false;
				done = true;
			}
		}
	}
	bool MoveSafe(char col, char row)
	{
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == Black)
		{
			if (gameBoard->FieldColour(col + 1, row + 1) == Empty && !gameBoard->CanBeKilled(col + 1, row + 1, Black))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row + 0] = Checker(Black);
				done = true;
				return true;
				
			}
			else if (gameBoard->FieldColour(col - 1, row + 1) == Empty && !gameBoard->CanBeKilled(col - 1, row + 1, Black))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row + 0] = Checker(Black);
				done = true;
				return true;
			}
		}
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == White)
		{
			if (gameBoard->FieldColour(col - 1, row - 1) == Empty && !gameBoard->CanBeKilled(col - 1, row - 1, White))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row - 2] = Checker(White);
				done = true;
				return true;
			}
			else if (gameBoard->FieldColour(col + 1, row - 1) == Empty && !gameBoard->CanBeKilled(col + 1, row - 1, White))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row - 2] = Checker(White);
				done = true;
				return true;
			}
		}
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == BlackQueen)
		{
			if (gameBoard->FieldColour(col - 1, row - 1) == Empty && !gameBoard->CanBeKilled(col - 1, row - 1, Black))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row - 2] = Checker(BlackQueen);
				done = true;
				return true;
			}
			else if (gameBoard->FieldColour(col + 1, row - 1) == Empty && !gameBoard->CanBeKilled(col + 1, row - 1, Black))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row - 2] = Checker(BlackQueen);
				done = true;
				return true;
			}
			else if (gameBoard->FieldColour(col - 1, row + 1) == Empty && !gameBoard->CanBeKilled(col - 1, row + 1, Black))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row + 0] = Checker(BlackQueen);
				done = true;
				return true;
			}
			else if (gameBoard->FieldColour(col + 1, row + 1) == Empty && !gameBoard->CanBeKilled(col + 1, row + 1, Black))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row + 0] = Checker(BlackQueen);
				done = true;
				return true;
			}
		}
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == WhiteQueen)
		{
			if (gameBoard->FieldColour(col + 1, row + 1) == Empty && !gameBoard->CanBeKilled(col + 1, row + 1, White))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row + 0] = Checker(WhiteQueen);
				done = true;
				return true;
			}
			else if (gameBoard->FieldColour(col - 1, row + 1) == Empty && !gameBoard->CanBeKilled(col - 1, row + 1, White))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row + 0] = Checker(WhiteQueen);
				done = true;
				return true;
			}
			else if (gameBoard->FieldColour(col - 1, row - 1) == Empty && !gameBoard->CanBeKilled(col - 1, row - 1, White))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row - 2] = Checker(WhiteQueen);
				done = true;
				return true;
			}
			else if (gameBoard->FieldColour(col + 1, row - 1) == Empty && !gameBoard->CanBeKilled(col + 1, row - 1, White))
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row - 2] = Checker(WhiteQueen);
				done = true;
				return true;
			}
		}
		done = false;
		return false;

	}
	void MoveAny(char col, char row)
	{
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == Black)
		{
			 if (gameBoard->FieldColour(col  +1, row + 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row + 0] = Checker(Black);
				done = true;
			}
			else if (gameBoard->FieldColour(col - 1, row + 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row + 0] = Checker(Black);
				done = true;
			}
		}
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == White)
		{
		    if (gameBoard->FieldColour(col - 1, row - 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row - 2] = Checker(White);
				done = true;
			}
			else if (gameBoard->FieldColour(col + 1, row - 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row - 2] = Checker(White);
				done = true;
			}
		}
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == BlackQueen)
		{
			if (gameBoard->FieldColour(col - 1, row - 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row - 2] = Checker(BlackQueen);
				done = true;
			}
			else if (gameBoard->FieldColour(col + 1, row - 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row - 2] = Checker(BlackQueen);
				done = true;
			}
			else if (gameBoard->FieldColour(col - 1, row + 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row + 0] = Checker(BlackQueen);
				done = true;
			}
			else if (gameBoard->FieldColour(col + 1, row + 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row + 0] = Checker(BlackQueen);
				done = true;
			}
		}
		if (gameBoard->currentState[toupper(col) - 65][row - 1].GetColour() == WhiteQueen)
		{
			if (gameBoard->FieldColour(col + 1, row + 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row + 0] = Checker(WhiteQueen);
				done = true;
			}else if (gameBoard->FieldColour(col - 1, row + 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row + 0] = Checker(WhiteQueen);
				done = true;
			}
			else if (gameBoard->FieldColour(col - 1, row - 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 66][row - 2] = Checker(WhiteQueen);
				done = true;
			}
			else if (gameBoard->FieldColour(col + 1, row - 1) == Empty)
			{
				gameBoard->currentState[col - 65][row - 1] = Checker(Empty);
				gameBoard->currentState[col - 64][row - 2] = Checker(WhiteQueen);
				done = true;
			}
		}
	
	}
	void AIMove()
	{
		list.clear();
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if (gameBoard->currentState[i][j].GetColour() == colour || gameBoard->currentState[i][j].GetColour()== queenC)
				{
					position checker = position((char)(i + 65), (char)j + 1);
					list.push_back(checker);
				}
			}
		std::random_shuffle(list.begin(), list.end());
		for(unsigned int i=0; i< list.size(); i++)
		{//if kill is possible then kill
			if (gameBoard->CanKill(list[i].x, list[i].y))
			{
				AIKill(list[i].x, list[i].y);
				if (done) break;
			}
		}
		for (unsigned int i = 0; i < list.size(); i++)
		{
			//tries to move a checker to a safe position
			MoveSafe(list[i].x, list[i].y);
			if (done) break;
		}
		for (unsigned int i = 0; i < list.size(); i++)
		{ // if no safe position available then move any
			MoveAny(list[i].x, list[i].y);
			if (done) break;
		}
		
	}
	Player(Colour col, int nr, bool aii)
	{
		
		AI = aii;
		score = 0;
		colour = col;
		index = nr;
		if (col = Black)
			queenC = BlackQueen;
		else
			queenC = WhiteQueen;
	}
private:
	bool AI;
	bool done;
	bool hasToKill=false;
	int index;
	int score;
	std::vector <position> list;
	Colour colour;
	Colour queenC;
};