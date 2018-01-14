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
#include <limits>

using namespace std;

const char * HELPER = "ConsoleLoggerHelper.exe";

Subject subject;


bool file_exist(const char *fileName);
void askAndSetPlayerCount();
bool inputCorrect(string);
int endGame();

int main()
{

	if (!file_exist(HELPER)) {
		cout << HELPER << " does not exist. We cannot run without it!" << endl;
		return endGame();
	}

	askAndSetPlayerCount();

	subject.add_observer(*new SoundObserver);
	subject.add_observer(*new WindowObserver());
	//subject.add_observer(*new WindowObserver(CConsoleLoggerEx().COLOR_GREEN));
	

	subject.notify();

	while (subject.gameloop())
	{
		subject.notify();
	}

	subject.notify();

	//char winner = subject.get_board.

	//TODO: Congrats you won

	return endGame();
}

void askAndSetPlayerCount()
{
	int players = 0;
	
	cout << "How many players are playing?" << endl;
	
	while (players < 2 || players > 5)
	{
		cin >> players;

		if (cin.fail())	
			cout << "Sorry, that's an invalid input!" << endl;
		else if (players > 5)
			cout << "Sorry, playing with more than 5 players makes no sense!" << endl;
		else if (players < 2)
			cout << "Sorry, playing with less than 2 players makes no sense!" << endl;
		else if (players < 2 || players > 5) {
			cout << "Sorry I didn't get that - please try again" << endl;
			players = 0;
		}
		cin.clear();
		cin.ignore();
	}

	subject.setPlayers(players);
	cout << "Sure, " << players << " sounds good!" << endl;
}

int endGame() {
	system("pause");
	return 0;
}

bool file_exist(const char *fileName)
{
	return experimental::filesystem::exists(fileName);
}