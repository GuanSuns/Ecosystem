#ifndef HERBIVORE_STATES_FIND_FOOD_H
#define HERBIVORE_STATES_FIND_FOOD_H

#include "BasicState.h"
#include "Parameters.h"
#include "MapItem.h"
#include "InfoDispatchMachine.h"
#include "MemorySystem.h"
#include "Random.h"
#include <cmath>
#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>


class Herbivore;

class HerbivoreStates_FindFood : public BasicState
{
public:
	HerbivoreStates_FindFood();
	~HerbivoreStates_FindFood();

public:
	static HerbivoreStates_FindFood* Instance();

	virtual void Enter(Creature*);
	virtual void Execute(Creature*);
	virtual void Resume(Creature*);
	virtual void Exit(Creature*);

private:
	inline bool canVisit(Location&);
	inline bool isVisitedAndUpdate(std::priority_queue<pathInfo, std::vector<pathInfo>, cmp>&, std::list<pathInfo>&, Location&, pathInfo&, Creature*);
	inline void getClosest(pathInfo&);
	inline bool arrive(pathInfo&, Herbivore*);
	inline void findRoad(std::list<pathInfo>&, Herbivore*);
	inline Creature* getDestination(std::vector<Info*>&, Herbivore*);
	inline Creature* getDestinationFromMemory(std::vector<MemoryItem>&, Herbivore*);
	inline int getDistance(Location&, Location&);
	inline int getMin(int, int);

public:
	std::priority_queue<pathInfo, std::vector<pathInfo>, cmp> findFood_Visited;
	std::list<pathInfo> findFood_Finished;

};

#endif

