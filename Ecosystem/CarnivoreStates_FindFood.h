#ifndef CARNIVORE_STATES_FIND_FOOD_H
#define CARNIVORE_STATES_FIND_FOOD_H

#include "BasicState.h"
#include "Parameters.h"
#include "MapItem.h"
#include "InfoDispatchMachine.h"
#include "Random.h"
#include <cmath>
#include <list>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>



class Carnivore;

class CarnivoreStates_FindFood : public BasicState
{
public:
	CarnivoreStates_FindFood();
	~CarnivoreStates_FindFood();

public:
	static CarnivoreStates_FindFood* Instance();

	virtual void Enter(Creature*);
	virtual void Execute(Creature*);
	virtual void Resume(Creature*);
	virtual void Exit(Creature*);

private:
	inline bool canVisit(Location&, Carnivore*);
	inline bool isVisitedAndUpdate(std::priority_queue<pathInfo, std::vector<pathInfo>, cmp>&, std::list<pathInfo>&, Location&, pathInfo&, Creature*);
	inline void getClosest(pathInfo&);
	inline bool arrive(pathInfo&, Carnivore*);
	inline void findRoad(std::list<pathInfo>&, Carnivore*);
	inline Creature* getDestination(std::vector<Info*>&, Carnivore*);
	
	inline int getDistance(Location&, Location&);
	inline int getMin(int, int);

public:
	std::priority_queue<pathInfo, std::vector<pathInfo>, cmp> findFood_Visited;
	std::list<pathInfo> findFood_Finished;

};

#endif

