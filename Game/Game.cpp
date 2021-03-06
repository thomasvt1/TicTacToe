// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "Observer.h"
#include "Subject.h"
#include "ConsoleLogger.h"
#include "WindowObserver.h"
#include "BuiltinWindow.h"
#include "SoundObserver.h"
#include <experimental/filesystem>

using namespace std;

const char * HELPER = "ConsoleLoggerHelper.exe";

Subject subject;


bool file_exist(const char *fileName);
void askAndSetPlayerCount();
bool input_correct(string);
void game_won();
void game_tie();
int endGame();

int main()
{

	if (!file_exist(HELPER)) {
		cout << HELPER << " does not exist. The game has less features!" << endl;
	}

	askAndSetPlayerCount();

	system("cls");

	//subject.add_observer(*new BuiltinWindow(subject));
	subject.add_observer(*new SoundObserver(subject));

	if (!file_exist(HELPER)) {
		subject.add_observer(*new WindowObserver(subject));
		//subject.add_observer(*new WindowObserver(CConsoleLoggerEx().COLOR_GREEN));
	}
	else // Run BuiltInWindow when file_exist false so we can show the board.
	{
		subject.add_observer(*new BuiltinWindow(subject));
	}
	
	subject.notify(); // First draw the board so player can see where to place

	while (subject.gameloop()) // Gameloop runs most of the logic and returns false if game ended
	{
		subject.notify(); // Notify after player turn ended
	}

	subject.notify(); // Notify so that the game reflects the winning state

	system("cls"); // Clear the input window

	// Check if the game is a tie or if the game has a winner
	if (subject.get_board_object().is_tie())
		game_tie();
	else
		game_won();

	return endGame();
}

void game_tie()
{
	cout << R"(.___________. __    ______        .___________.    ___       ______        .___________. __   _______ 
|           ||  |  /      |       |           |   /   \     /      |       |           ||  | |   ____|
`---|  |----`|  | |  ,----' ______`---|  |----`  /  ^  \   |  ,----' ______`---|  |----`|  | |  |__   
    |  |     |  | |  |     |______|   |  |      /  /_\  \  |  |     |______|   |  |     |  | |   __|  
    |  |     |  | |  `----.           |  |     /  _____  \ |  `----.           |  |     |  | |  |____ 
    |__|     |__|  \______|           |__|    /__/     \__\ \______|           |__|     |__| |_______|
                                                                                                      )" << 
		endl << endl;

	cout << endl << R"(                                       /;    ;\
                                   __  \\____//
                                  /{_\_/   `'\____
                                  \___   (o)  (o  }
       _____________________________/          :--'  
   ,-,'`@@@@@@@@       @@@@@@         \_    `__\
  ;:(  @@@@@@@@@        @@@             \___(o'o)
  :: )  @@@@          @@@@@@        ,'@@(  `===='       
  :: : @@@@@:          @@@@         `@@@:
  :: \  @@@@@:       @@@@@@@)    (  '@@@'
  ;; /\      /`,    @@@@@@@@@\   :@@@@@)
  ::/  )    {_----------------:  :~`,~~;
 ;;'`; :   )                  :  / `; ;
;;;; : :   ;                  :  ;  ; :              
`'`' / :  :                   :  :  : :
    )_ \__;      ";"          :_ ;  \_\       `,','
    :__\  \    * `,'*         \  \  :  \   *  8`;'*  *
        `^'     \ :/           `^'  `-^-'   \v/ :  \/ )" <<
		endl << endl;

	cout << "TIE! - Too bad next time try better!" << endl;
}

void game_won()
{
	cout << R"( _____                             _         _       _   _                 
/  __ \                           | |       | |     | | (_)                
| /  \/ ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___ 
| |    / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __|
| \__/\ (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \
 \____/\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___/
                    __/ |                                                  
                   |___/                                                   )" << endl << endl;


	cout << "Congratulations player " << subject.get_winner() << " you just won the game!" << endl;
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