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
	cout << R"(___________.__                                 /\          _____                        .__                
\__    ___/|  |__   ____   _____ _____    _____)/______   /  _  \   _____ _____  _______|__| ____    ____  
  |    |   |  |  \ /  _ \ /     \\__  \  /  ___//  ___/  /  /_\  \ /     \\__  \ \___   /  |/    \  / ___\ 
  |    |   |   Y  (  <_> )  Y Y  \/ __ \_\___ \ \___ \  /    |    \  Y Y  \/ __ \_/    /|  |   |  \/ /_/  >
  |____|   |___|  /\____/|__|_|  (____  /____  >____  > \____|__  /__|_|  (____  /_____ \__|___|  /\___  / 
                \/             \/     \/     \/     \/          \/      \/     \/      \/       \//_____/  )" << endl;

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