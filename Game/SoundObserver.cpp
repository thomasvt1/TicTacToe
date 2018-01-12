#include "stdafx.h"
#include "SoundObserver.h"
#include "Subject.h"
#include <windows.h>
#include "iostream"


using namespace std;

void SoundObserver::update(Subject &s)
{
	Beep(523, 250);
}