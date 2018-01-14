#include "stdafx.h"
#include "WindowObserver.h"
#include "iostream"
#include "Subject.h"
#include "ConsoleLogger.h"


using namespace std;

void WindowObserver::update(Subject &s)
{
	if (color != NULL)
		console.cls(color);
	else
		console.cls();

	print(s);
}

WindowObserver::WindowObserver()
{
	setupConsole();
}

WindowObserver::WindowObserver(enum CConsoleLoggerEx::enumColors col)
{
	setupConsole();
	color = col;
}

void WindowObserver::setupConsole()
{
	console.Create("WindowObserver");
	console.printf("WindowObserver is waiting for data! \n");
}

WindowObserver::~WindowObserver()
{
	console.Close();

}

void WindowObserver::print(Subject &s)
{
	string * board = s.get_board();

	int k, l, p;

	for (int o = 0; o < 4; o++)
	{
		p = o * 4;
		for (int j = 0; j < 4; j++)
		{
			k = j * 16;
			for (int i = 0; i < 4; i++)
			{
				int kip = k + i + p;
				string line = board[kip];
				if (line.size() == 1)
					line += " ";

				if (i == 0) {
					string xyz = "   " + line + " ";
					console.printf(xyz.c_str());
				}
				else {
					string xyz = "|  " + line + " ";
					console.printf(xyz.c_str());
				}

			}
		}
		if (o != 3)
			console.printf("\n  ______________________   _____________________   _____________________   _____________________\n");
	}
	console.printf("\n");
}