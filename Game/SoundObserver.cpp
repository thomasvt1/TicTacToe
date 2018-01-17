#include "stdafx.h"
#include "SoundObserver.h"
#include "Subject.h"
#include "iostream"
#include <Windows.h>



using namespace std;

SoundObserver::SoundObserver(Subject &sub) : s(sub)
{
}

SoundObserver::~SoundObserver()
{
}

void SoundObserver::update()
{
	if (s.get_board_object().is_winner())
	{
		PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME);
	}
	else
	{
		int beep = 300 + (100 * (s.get_board_object().get_player_int() + 1));
		Beep(beep, 250);
	}
}