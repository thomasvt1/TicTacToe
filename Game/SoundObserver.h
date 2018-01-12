#pragma once
class Subject;
#include "Observer.h"

class SoundObserver : public Observer
{
public:
	void update(Subject &s);
};