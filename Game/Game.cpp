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

bool inputCorrect(string);
bool file_exist(const char *fileName);
int endGame();

int main()
{

	if (!file_exist(HELPER)) {
		cout << HELPER << " does not exist. We cannot run without it!" << endl;
		return endGame();
	}

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

int endGame() {
	system("pause");
	return 0;
}

bool file_exist(const char *fileName)
{
	return experimental::filesystem::exists(fileName);
}