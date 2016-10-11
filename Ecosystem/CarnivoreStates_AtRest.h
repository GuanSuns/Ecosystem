#ifndef CARNIVORE_STATES_AT_REST_H
#define CARNIVORE_STATES_AT_REST_H

#include "BasicState.h"
#include "CarnivoreStates_Escape.h"
#include "CarnivoreStates_FindFood.h"
#include "CarnivoreStates_FindWater.h"
#include "Random.h"
#include <iostream>

class Carnivore;

class CarnivoreStates_AtRest : public BasicState
{
public:
	CarnivoreStates_AtRest();
	~CarnivoreStates_AtRest();

public:
	static CarnivoreStates_AtRest* Instance();

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
