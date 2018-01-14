#include "stdafx.h"
#include <string>
#include <list>
#include "Subject.h"
#include <iostream>

using namespace std;

Subject::Subject()
{
	board = Board();
}


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
	return board.get_board();
}

bool Subject::gameloop()
{
	handleInput();
	board.switchTurn();
	return !board.isWinner();
}

void Subject::handleInput()
{
	bool incorrect = true;
	string place;

	char turn = board.get_turn();

	cout << endl << "Player " << turn << " Where would you like to put your mark? " << endl;

	while (incorrect) {
		cin >> place;

		place[0] = toupper(place[0]);
		string input = place;

		incorrect = !board.inputCorrect(place);

		if (incorrect)
			cout << input << " - is not a valid location" << endl;
	}
	board.changeField(place);
}