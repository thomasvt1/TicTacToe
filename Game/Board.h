#pragma once
#include "string"

using namespace std;

class Board
{
public:
	Board();
	string * get_board();
	bool changeField(string place);
	bool isWinner();
	bool inputCorrect(string place);
	void switchTurn();
	char get_turn();


private:
	string board[64];
	void fillBoard();
	char turn = 'X';
	string winDetection();
};

