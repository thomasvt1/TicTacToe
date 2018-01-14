// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "Observer.h"
#include "Subject.h"
#include "ConsoleLogger.h"
#include "WindowObserver.h"
#include "SoundObserver.h"
#include <experimental/filesystem>

using namespace std;

const char * HELPER = "ConsoleLoggerHelper.exes";

Subject subject;

void changeField(string place);
void handleInput();
bool inputCorrect(string);
bool file_exist(const char *fileName);
int endGame();

string * board = 0;

int main()
{
	board = subject.get_board();

	

	if (!file_exist(HELPER)) {
		cout << HELPER << " does not exist. We cannot run without it!" << endl;
		return endGame();
	}

	//subject.add_observer(*new SoundObserver);
	subject.add_observer(*new WindowObserver());
	//subject.add_observer(*new WindowObserver(CConsoleLoggerEx().COLOR_GREEN));
	

	subject.notify();

	bool won = false;
	
	while (!won) {
		handleInput();
		subject.switchTurn();

		won = subject.isWinner();
	}

	return endGame();
}

int endGame() {
	system("pause");
	return 0;
}

bool file_exist(const char *fileName)
{
	return experimental::filesystem::exists(fileName);
}

void handleInput()
{
	bool incorrect = true;
	string place;

	char turn = subject.get_turn();

	cout << endl << "Player " << turn << " Where would you like to put your mark? " << endl;

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

void changeField(string place)
{
	char turn = subject.get_turn();

	for (int i = 0; i < 64; i++)
		if (place == board[i])
			board[i] = turn;
	subject.notify();
}

bool inputCorrect(string place)
{
	for (int i = 0; i < 64; i++)
		if (place == board[i])
			return true;
	return false;
}