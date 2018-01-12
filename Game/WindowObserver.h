#pragma once
#include "Observer.h"
#include "ConsoleLogger.h"

class WindowObserver : public Observer
{
public:
	void update(Subject &s);
	WindowObserver();
private:
	void print(Subject &s);
	CConsoleLoggerEx console;
};