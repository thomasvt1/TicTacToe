#include "stdafx.h"
#include "SoundObserver.h"
#include "Subject.h"
#include "iostream"


using namespace std;

void SoundObserver::update(Subject &s) {
	cout << " times updated." << endl;
}