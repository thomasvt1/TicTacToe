#pragma once
class Subject;

class Observer
{
public:
	virtual void update() = 0;
};