#pragma once
#include "Observer.h"
#include "ConsoleLogger.h"

class BuiltinWindow : public Observer
{
public:
	BuiltinWindow(Subject &s);
	~BuiltinWindow();
	void update();
private:
	void print();
	Subject &s;
};