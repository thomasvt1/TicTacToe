#include "stdafx.h"
#include <string>
#include <list>
#include "Subject.h"
#include <iostream>

using namespace std;


void Subject::add_observer(Observer& _observer) {
	observers.push_back(&_observer);
}

void Subject::notify() {
	for (iterator it = observers.begin(); it != observers.end(); it++) {
		(*it)->update(*this);
	}
}

string * Subject::get_space() {
	return space;
}

char Subject::get_turn() {
	return turn;
}

Subject::Subject(void) {
	fillSpace();
}

void Subject::handleInput() {
	bool incorrect = true;
	string place;

	notify();

	cout << endl << endl << "Player " << turn << " Where would you like to put your mark? " << endl;

	while (incorrect) {
		cin >> place;

		place[0] = toupper(place[0]);
		string input = place;

		incorrect = !inputCorrect(place);

		if (incorrect)
			cout << input << " - is not a valid location" << endl;
	}

	changeField(place);
}

void Subject::fillSpace() {

	string letter[] = { "A", "B", "C", "D", "E", "F", "G", "H" };

	for (int i = 0; i < 64; i++)
	{
		int y = i / 8;
		space[i] = letter[(i / 8)] + to_string(i - (y * 8));
	}
}

void Subject::changeField(string place) {
	for (int i = 0; i < 64; i++)
		if (place == space[i])
			space[i] = turn;
}

void Subject::setTurn(char c) {
	turn = c;
}


void Subject::switchTurn() {
	switch (turn) {
		case 'X':
			turn = 'O';
			break;
		case 'O':
			turn = 'X';
			break;
	}
}

bool Subject::inputCorrect(string place) {
	for (int i = 0; i < 64; i++)
		if (place == space[i])
			return true;
	return false;
}

string Subject::winDetection() {
	int k, l, p;
	bool win = false;
	for (int j = 0; j < 4; j++)
	{
		k = j * 16;
		for (int i = 0; i < 16; i += 4)
		{
			l = k + i;
			if (space[l] == space[l + 1] && space[l] == space[l + 2] && space[l] == space[l + 3])
				win = true;
		}
	}
	if (win)
		return space[l];
	return false;
}