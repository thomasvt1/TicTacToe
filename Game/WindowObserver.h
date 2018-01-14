#pragma once
#include "Observer.h"
#include "ConsoleLogger.h"

class WindowObserver : public Observer
{
public:
	void update(Subject &s);
	WindowObserver(enum CConsoleLoggerEx::enumColors);
	WindowObserver();
	~WindowObserver();
private:
	void print(Subject &s);
	CConsoleLoggerEx console;
	enum CConsoleLoggerEx::enumColors color;
};