#ifndef CREATURE_VECTOR_H
#define CREATURE_VECTOR_H

#include <iostream>
#include <vector>
#include <list>
#include <string.h>
#include <math.h>
#include "Creature.h"
#include "BasicAnimal.h"
#include "MapItem.h"
#include "Location.h"
#include "InfoDispatchMachine.h"

class CreatureVector
{
public:
	CreatureVector();
	~CreatureVector();

public:
	void Update();
	void Add(Creature*);
	void Add(Creature*, int);

    int getCntBySpeciesID(int);
    void clearCnt();

private:
	std::vector<Creature*> creatureVector;
	std::list<Location> visitedList;
	std::list<Creature*> groupMember;

private:
	void UpdateGroup();
	void UpdateIndividual();
	void UpdateUnit(Creature*, Creature*);

	inline int distance(Location& , Location& );
	inline int getMin(int, int);
	inline bool isVisited(Location& );
	inline bool canVisit(Location& , Location& , Location& , Creature*);
	inline int getCnt(int);

    void cntBySpeciesID(int);
    int cntSheep;
    int cntCow;
    int cntWolf;
    int cntTiger;

};

extern CreatureVector mCreatureVector;

#endif

