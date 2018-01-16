#pragma once
class Subject;
#include "Observer.h"

class SoundObserver : public Observer
{
public:
	SoundObserver();
	~SoundObserver();
	void update(Subject &s);
};