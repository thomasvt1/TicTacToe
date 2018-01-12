#include "stdafx.h"
#include "WindowObserver.h"
#include "iostream"
#include "Subject.h"

using namespace std;

void WindowObserver::update(Subject &s) {
	cout << "Subject's name is changed as '" << s.get_name() << "'." << endl;
}