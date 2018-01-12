#include "stdafx.h"
#include <string>
#include <list>
#include "Subject.h"
#include <iostream>

using namespace std;


void Subject::add_observer(Observer& _observer)
{
	observers.push_back(&_observer);
}

void Subject::notify()
{
	for (iterator it = observers.begin(); it != observers.end(); it++)
	{
		(*it)->update(*this);
	}
}

string * Subject::get_board()
{
	return board;
}

char Subject::get_turn()
{
	return turn;
}

Subject::Subject(void)
{
	fillSpace();
}

void Subject::fillSpace()
{
	string letter[] = { "A", "B", "C", "D", "E", "F", "G", "H" };

	for (int i = 0; i < 64; i++)
	{
		int y = i / 8;
		board[i] = letter[(i / 8)] + to_string(i - (y * 8));
	}
}

void Subject::changeField(string place)
{
	for (int i = 0; i < 64; i++)
		if (place == board[i])
			board[i] = turn;
}


void Subject::switchTurn()
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

bool Subject::inputCorrect(string place)
{
	for (int i = 0; i < 64; i++)
		if (place == board[i])
			return true;
	return false;
}

bool Subject::isWinner()
{
	return winDetection().length() != 0;
}

string Subject::winDetection()
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