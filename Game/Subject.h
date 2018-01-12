#pragma once

#include "list"
#include "string"
#include "Observer.h"

using namespace std;

class Subject
{
typedef list<Observer*>::iterator iterator;

private:
	list<Observer*> observers;
	string name;
	string board[64];
	char turn = 'X';
	void fillSpace();
	void changeField(string place);
	bool inputCorrect(string place);

public:
	void add_observer(Observer&);
	void notify();
	char get_turn();
	string * get_board();
	string winDetection();
	bool isWinner();
	void switchTurn();
	Subject();
};