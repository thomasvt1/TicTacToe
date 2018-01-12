#pragma once
#include "Observer.h"
//class Observer;

class WindowObserver : public Observer
{
public:
	void update(Subject &s);
};