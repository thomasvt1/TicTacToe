#include "stdafx.h"
#include "Board.h"
#include "iostream"


Board::Board()
{
	fillBoard();
}

Board::~Board()
{
}

string * Board::get_board()
{
	return board;
}

bool Board::changeField(string place)
{
	for (int i = 0; i < 64; i++)
		if (place == board[i])
		{
			board[i] = players[turn];
			return true;
		}
	return false;
}

void Board::switchTurn()
{
	turn += 1;
	if (turn >= playercount)
		turn = 0;
}

void Board::fillBoard()
{
	string letter[] = { "A", "B", "C", "D", "E", "F", "G", "H" };

	for (int i = 0; i < 64; i++)
	{
		int y = i / 8;
		board[i] = letter[(i / 8)] + to_string(i - (y * 8));
	}
}

bool Board::inputCorrect(string place)
{
	if (place.length() != 2)
		return false;
	for (int i = 0; i < 64; i++)
		if (place == board[i])
			return true;
	return false;
}

bool Board::isWinner()
{
	return winDetection().length() != 0;
}

char Board::get_turn()
{
	return players[turn];
}

void Board::setPlayers(int players)
{
	playercount = players;
}

string Board::winDetection()
{
	int k, l, p;
	bool win = false;
	for (int l = 0; l < 64; l += 4)
	{
		if (board[l] == board[l + 1] && board[l] == board[l + 2] && board[l] == board[l + 3])			//horizontal from front view
		{
			return board[l];
		}

		if (l>-1 && l<4 || l>15 && l<20 || l>31 && l<36 || l>47 && l<52)												//vertical from front view
		{
			if (board[l] == board[l + 4] && board[l] == board[l + 8] && board[l] == board[l + 12])
			{
				return board[l];
			}
		}

		if (l == 0 || l == 16 || l == 32 || l == 48)																	//crosses from front view
		{
			if ((board[l] == board[l + 5] && board[l] == board[l + 10] && board[l] == board[l + 15]) ||
				(board[l + 3] == board[l + 6] && board[l] == board[l + 9] && board[l] == board[l + 12]))
			{
				return board[l];
			}
		}
	}
	for (int j = 0; j < 16; j++)
	{
		if (board[j] == board[j + 16] && board[j] == board[j + 32] && board[j] == board[j + 48])			//depth from front view
		{
			return board[j];
		}

		if (j == 0 || j == 4 || j == 8 || j == 12)
		{
			if (board[j] == board[j + 17] && board[j] == board[j + 34] && board[j] == board[j + 51])	//diagnal from above view
			{
				return board[j];
			}
		}

		if (j == 3 || j == 7 || j == 11 || j == 16)
		{
			if (board[j] == board[j + 15] && board[j] == board[j + 30] && board[j] == board[j + 45])	//other diagnal from above view
			{
				return board[j];
			}
		}
		if ((board[0] == board[21] && board[0] == board[42] && board[0] == board[63]) ||						//crosses through the cube
			(board[3] == board[22] && board[3] == board[41] && board[3] == board[60]) ||
			(board[12] == board[25] && board[12] == board[38] && board[12] == board[51]) ||
			(board[15] == board[26] && board[15] == board[37] && board[15] == board[48])
			)
		{
			return board[j];
		}
	}
	return "";
}