#ifndef HERBIVORE_STATES_AT_REST_H
#define HERBIVORE_STATES_AT_REST_H

#include "BasicState.h"
#include "HerbivoreStates_Escape.h"
#include "HerbivoreStates_FindFood.h"
#include "HerbivoreStates_FindWater.h"
#include "Random.h"
#include <iostream>


class HerbivoreStates_AtRest : public BasicState
{
public:
	HerbivoreStates_AtRest();
	~HerbivoreStates_AtRest();

public:
	static HerbivoreStates_AtRest* Instance();
	
	virtual void Enter(Creature*);
	virtual void Execute(Creature*);
	virtual void Resume(Creature*);
	virtual void Exit(Creature*);

private:
	bool IsHungry(Creature*);
	bool IsThirsty(Creature*);
	bool IsMove(Creature*);
};


#endif

