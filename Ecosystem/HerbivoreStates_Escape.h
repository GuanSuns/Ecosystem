#ifndef HERBIVORE_STATES_ESCAPE_H
#define HERBIVORE_STATES_ESCAPE_H

#include "BasicState.h"
#include "InfoDispatchMachine.h"
#include "Vector2D.h"
#include "Random.h"

#include <cmath> 
#include <iostream>

class Herbivore;

class HerbivoreStates_Escape :	public BasicState
{
public:
	HerbivoreStates_Escape();
	~HerbivoreStates_Escape();

public:
	static HerbivoreStates_Escape* Instance();

	virtual void Enter(Creature*);
	virtual void Execute(Creature*);
	virtual void Resume(Creature*);
	virtual void Exit(Creature*);

private:
	inline int getDistance(Location&, Location&);
	inline int getMin(int, int);

};
#endif

