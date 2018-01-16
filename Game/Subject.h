#pragma once

#include "list"
#include "string"
#include "Observer.h"
#include "Board.h"

using namespace std;

class Subject
{
typedef list<Observer*>::iterator iterator;

private:
	list<Observer*> observers;
	string name;
	Board board;
	void handle_input();
	void print_header();

public:
	Subject();
	~Subject();
	void add_observer(Observer&);
	void clear_observers();
	void notify();
	string * get_board();
	void set_players(int);
	Board get_board_object();
	string get_winner();
	bool gameloop();
};