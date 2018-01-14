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
	void handleInput();
	void printHeader();

public:
	void add_observer(Observer&);
	void notify();
	string * get_board();
	void setPlayers(int);
	bool gameloop();
	Subject();
};