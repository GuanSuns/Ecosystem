#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "BasicAnimal.h"
#include "CreatureVector.h"
#include "Carnivore_GlobalStates.h"
#include "CarnivoreStates_AtRest.h"
#include <math.h>
#include <list>
#include <string.h>

class Carnivore : public BasicAnimal
{
public:
	Carnivore();
	Carnivore(int, int, int, BasicState*);
	~Carnivore();

public:
	virtual void Born(int);
	virtual void Update();
	virtual void Die();
	virtual void AddState(BasicState*);
	virtual void FinishCurrentState();
	virtual bool add(Creature*);

	std::list<Location> carnivore_VisitedPoint;

private:
	inline bool isVisited(std::list<Location>&, Location&);
	inline int getCnt(int);


};

#endif

