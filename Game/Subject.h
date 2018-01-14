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

public:
	void add_observer(Observer&);
	void notify();
	string * get_board();
	bool gameloop();
	Subject();
};