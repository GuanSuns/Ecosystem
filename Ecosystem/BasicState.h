#ifndef BASIC_STATE_H
#define BASIC_STATE_H

#include "Location.h"

struct pathInfo
{
	Location father;
	Location location;
	int distance;
	int pace;

	pathInfo()
	{
		this->distance = 0;
		this->pace = 0;
		father.x = father.y = location.x = location.y = 0;
	}
};

struct cmp
{
	bool operator() (pathInfo a, pathInfo b)
	{
		return a.distance > b.distance;
	}

};

class Creature;

class BasicState
{
public:
	BasicState();
	~BasicState();

public:
	virtual void Enter(Creature*) = 0;
	virtual void Execute(Creature*) = 0;
	virtual void Resume(Creature*) = 0;
	virtual void Exit(Creature*) = 0;
};

#endif

