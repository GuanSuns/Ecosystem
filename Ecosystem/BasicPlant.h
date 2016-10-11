#ifndef BASIC_PLANT_H
#define BASIC_PLANT_H

#include "Creature.h"
#include "Vector2D.h"
#include "BasicState.h"
#include "MapItem.h"
#include "Parameters.h"
#include "CreatureVector.h"

#include <math.h>
#include <list>
#include <string.h>

class BasicPlant : public Creature
{
public:
	BasicPlant();
	~BasicPlant();
	BasicPlant(int, int, int, BasicState*);

public:
	virtual void Update();
	virtual void Die();
	virtual void Born(int);

	virtual bool add(Creature*);

protected:
	int groupSize;	
	std::list<Location> plants_VisitedPoint;

protected:
	inline bool isVisited(std::list<Location>&, Location&);
	inline int getCnt(int);
	int distance(Location&, Location&);
	int getMin(int, int);

};


#endif

