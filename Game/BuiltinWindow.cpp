#include "stdafx.h"
#include "BuiltinWindow.h"
#include "iostream"
#include "Subject.h"
#include "ConsoleLogger.h"


using namespace std;

BuiltinWindow::BuiltinWindow(Subject &sub) : s(sub)
{
}

BuiltinWindow::~BuiltinWindow()
{
}

void BuiltinWindow::update()
{
	print();
}

void BuiltinWindow::print()
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
					cout << xyz;
				}
				else {
					string xyz = "|  " + line + " ";
					cout << xyz.c_str();
					//console.printf(xyz.c_str());
				}

			}
		}
		if (o != 3)
			cout << "\n  ______________________   _____________________   _____________________   _____________________\n";
			//console.printf("\n  ______________________   _____________________   _____________________   _____________________\n");
	}
	//console.printf("\n");
	cout << endl;
}