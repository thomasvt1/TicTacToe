#include "stdafx.h"
#include "SoundObserver.h"
#include "Subject.h"
#include <windows.h>
#include "iostream"


using namespace std;

SoundObserver::SoundObserver()
{
}

SoundObserver::~SoundObserver()
{
}

void SoundObserver::update(Subject &s)
{
	int beep = 200 + (50* s.get_board_object().get_player_int());
	Beep(beep, 250);
}