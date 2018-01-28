#pragma once
#include "Observer.h"
#include "ConsoleLogger.h"

class WindowObserver : public Observer
{
public:
	WindowObserver(Subject &s);
	~WindowObserver();
	void update();
	WindowObserver(Subject &s, enum CConsoleLoggerEx::enumColors);
private:
	void print();
	Subject &s;
	CConsoleLoggerEx console;
	enum CConsoleLoggerEx::enumColors color;
	void WindowObserver::setupConsole();
};