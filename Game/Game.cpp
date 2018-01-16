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

const char * HELPER = "ConsoleLoggerHelper.exe";

Subject subject;


bool file_exist(const char *fileName);
void askAndSetPlayerCount();
bool input_correct(string);
int endGame();

int main()
{

	if (!file_exist(HELPER)) {
		cout << HELPER << " does not exist. We cannot run without it!" << endl;
		return endGame();
	}

	askAndSetPlayerCount();

	WindowObserver wo = WindowObserver();

	subject.add_observer(*new SoundObserver);
	subject.add_observer(wo);
	//subject.add_observer(*new WindowObserver(CConsoleLoggerEx().COLOR_GREEN));
	

	subject.notify();

	while (subject.gameloop())
	{
		subject.notify();
	}

	subject.notify();

	system("cls");

	cout << R"( _____                             _         _       _   _                 
/  __ \                           | |       | |     | | (_)                
| /  \/ ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___ 
| |    / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __|
| \__/\ (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \
 \____/\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___/
                    __/ |                                                  
                   |___/                                                   )" << endl << endl;


	cout << "Congratulations player " << subject.get_winner() << " you just won the game!" << endl;

	return endGame();
}

void askAndSetPlayerCount()
{
	int players = 0;
	
	cout << "How many players are playing?" << endl;
	cin >> players;
	
	/*
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
	*/

	subject.set_players(players);
	cout << "Sure, " << players << " sounds good!" << endl;
}

int endGame() {
	system("pause");
	subject.clear_observers();
	return 0;
}

bool file_exist(const char *fileName)
{
	return experimental::filesystem::exists(fileName);
}