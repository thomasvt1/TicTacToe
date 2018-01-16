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

Subject::~Subject()
{
}

void Subject::add_observer(Observer& _observer)
{
	observers.push_back(&_observer);
}

void Subject::clear_observers()
{
	observers.clear();
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

string Subject::get_winner()
{
	return board.winDetection();
}

void Subject::setPlayers(int players)
{
	board.setPlayers(players);
}

bool Subject::gameloop()
{
	system("cls");
	
	printHeader();

	handleInput();
	board.switchTurn();
	return !board.isWinner();
}

void Subject::printHeader()
{
	cout << R"(___________.__                                 /\    _____                        .__                
\__    ___/|  |__   ____   _____ _____    _____)/   /  _  \   _____ _____  _______|__| ____    ____  
  |    |   |  |  \ /  _ \ /     \\__  \  /  ___/   /  /_\  \ /     \\__  \ \___   /  |/    \  / ___\ 
  |    |   |   Y  (  <_> )  Y Y  \/ __ \_\___ \   /    |    \  Y Y  \/ __ \_/    /|  |   |  \/ /_/  >
  |____|   |___|  /\____/|__|_|  (____  /____  >  \____|__  /__|_|  (____  /_____ \__|___|  /\___  / 
                \/             \/     \/     \/           \/      \/     \/      \/       \//_____/  )" << endl;

	cout << R"( _____ _        _____            _____              _________  __   __ _      ______ _     _   _ _____ 
|_   _(_)      |_   _|          |_   _|            /   |  _  \ \ \ / /| |     | ___ \ |   | | | /  ___|
  | |  _  ___    | | __ _  ___    | | ___   ___   / /| | | | |  \ V / | |     | |_/ / |   | | | \ `--. 
  | | | |/ __|   | |/ _` |/ __|   | |/ _ \ / _ \ / /_| | | | |  /   \ | |     |  __/| |   | | | |`--. \
  | | | | (__    | | (_| | (__    | | (_) |  __/ \___  | |/ /  / /^\ \| |____ | |   | |___| |_| /\__/ /
  \_/ |_|\___|   \_/\__,_|\___|   \_/\___/ \___|     |_/___/   \/   \/\_____/ \_|   \_____/\___/\____/ 
                                                                                                       
                                                                                                       )" << endl;
	cout << string(10, '\n');
}

void Subject::handleInput()
{
	bool incorrect = true;
	string place;

	cout << endl << "Player " << board.get_turn() << " Where would you like to put your mark? " << endl;

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