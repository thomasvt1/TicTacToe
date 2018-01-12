#pragma once

#include "list"
#include "string"
#include "Observer.h"

//class Observer;

class Subject
{
typedef std::list<Observer*>::iterator iterator;

private:
	std::list<Observer*> observers;
	std::string name;

public:
	void add_observer(Observer&);
	void notify();
	void set_name(std::string);
	std::string get_name();
};