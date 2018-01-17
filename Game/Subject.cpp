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
		(*it)->update();
	}
}

string * Subject::get_board()
{
	return board.get_board();
}

string Subject::get_winner()
{
	return board.win_detection();
}

void Subject::set_players(int players)
{
	board.set_players(players);
}

Board Subject::get_board_object()
{
	return board;
}

bool Subject::gameloop()
{
	print_header();

	handle_input();
	board.switch_turn();

	system("cls");

	return !board.is_winner();
}

void Subject::print_header()
{
	cout << string(2, '\n');
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
	cout << string(3, '\n');
}

void Subject::handle_input()
{
	bool incorrect = true;
	string place;

	cout << endl << "Player " << board.get_turn() << " Where would you like to put your mark? " << endl;

	while (incorrect) {
		cin >> place;

		place[0] = toupper(place[0]);
		string input = place;

		incorrect = !board.input_correct(place);

		if (incorrect)
			cout << input << " - is not a valid location" << endl;
	}
	board.changefield(place);
}