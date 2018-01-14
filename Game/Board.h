#pragma once
#include "string"

using namespace std;

class Board
{
public:
	Board();
	string * get_board();
	bool changeField(string place);
	void setPlayers(int players);
	bool isWinner();
	bool inputCorrect(string place);
	void switchTurn();
	char get_turn();


private:
	char players[5] = { 'X', 'O' , 'Z', 'S', 'B'};
	int playernum = 2;
	string board[64];
	void fillBoard();
	char turn;
	string winDetection();
};

