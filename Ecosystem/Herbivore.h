#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "BasicAnimal.h"
#include "CreatureVector.h"
#include "Herbivore_GlobalStates.h"
#include "HerbivoreStates_AtRest.h"
#include <math.h>
#include <list>
#include <string.h>

class Herbivore : public BasicAnimal
{
public:
	Herbivore();
	Herbivore(int, int, int, BasicState*);
	~Herbivore();

public:
	virtual void Born(int);
	virtual void Update();
	virtual void Die();
	virtual void AddState(BasicState*);
	virtual void FinishCurrentState();
	virtual bool add(Creature*);

	std::list<Location> herbivore_VisitedPoint;

protected:
	inline bool isVisited(std::list<Location>&, Location&);
	inline int getCnt(int);





};

#endif

