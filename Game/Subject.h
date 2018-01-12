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
	string space[64];
	char turn = 'X';
	void fillSpace();
	void handleInput();
	void changeField(string place);
	bool inputCorrect(string place);
	string winDetection();
	

public:
	void add_observer(Observer&);
	void notify();
	char get_turn();
	string * get_space();
	void switchTurn();
	void setTurn(char);
	Subject();
};