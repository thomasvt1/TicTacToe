#include "stdafx.h"
#include <string>
#include <list>
#include "Subject.h"

using namespace std;

void Subject::add_observer(Observer& _observer) {
	observers.push_back(&_observer);
}

void Subject::notify() {
	for (iterator it = observers.begin(); it != observers.end(); it++) {
		(*it)->update(*this);
	}
}

void Subject::set_name(string s) {
	name = s;
	notify();
}

string Subject::get_name() {
	return name;
}
