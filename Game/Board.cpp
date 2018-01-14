#include "stdafx.h"
#include "Board.h"


Board::Board()
{
	fillBoard();
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
			board[i] = turn;
			return true;
		}
	return false;
}

void Board::switchTurn()
{
	switch (turn) {
	case 'X':
		turn = 'O';
		break;
	case 'O':
		turn = 'X';
		break;
	}
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
	return turn;
}

string Board::winDetection()
{
	int k, l, p;
	bool win = false;
	for (int j = 0; j < 4; j++)
	{
		k = j * 16;
		for (int i = 0; i < 16; i += 4)
		{
			l = k + i;
			if ((board[l] == board[l + 1] && board[l] == board[l + 2] && board[l] == board[l + 3]) ||
				(board[l] == board[l + 4] && board[l] == board[l + 8] && board[l] == board[l + 12]) ||
				(board[l] == board[l + 5] && board[l] == board[l + 10] && board[l] == board[l + 15]) ||
				(board[l + 3] == board[l + 6] && board[l + 3] == board[l + 9] && board[l + 3] == board[l + 12]))
			{
				return board[l];
			}
		}
	}
	return "";
}