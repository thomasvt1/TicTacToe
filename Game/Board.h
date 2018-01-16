#pragma once
#include "string"

using namespace std;

class Board
{
public:
	Board();
	~Board();
	string * get_board();
	bool changeField(string);
	void setPlayers(int);
	bool isWinner();
	bool inputCorrect(string);
	void switchTurn();
	char get_turn();
	string winDetection();

private:
	char players[5] = { 'X', 'O' , 'Z', 'S', 'B'};
	int turn = 0;
	int playercount = 2;
	string board[64];
	void fillBoard();
};