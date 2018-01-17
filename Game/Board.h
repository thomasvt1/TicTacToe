#pragma once
#include "string"

using namespace std;

class Board
{
public:
	Board();
	~Board();
	string * get_board();
	bool changefield(string);
	void set_players(int);
	bool is_winner();
	bool input_correct(string);
	void switch_turn();
	char get_turn();
	string win_detection();
	int get_player_int();
	bool is_tie();

private:
	char players[5] = { 'X', 'O' , 'Z', 'S', 'B'};
	int turn = 0;
	int playercount = 2;
	string board[64];
	void fillBoard();
};