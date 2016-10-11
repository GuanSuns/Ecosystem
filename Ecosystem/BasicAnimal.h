#ifndef BASIC_ANIMAL_H
#define BASIC_ANIMAL_H

#include "Creature.h"
#include "Vector2D.h"
#include "BasicState.h"
#include "MapItem.h"
#include "InfoDispatchMachine.h"
#include "Random.h"
#include "Herbivore_GlobalStates.h"
#include "BasicPlant.h"
#include "MemorySystem.h"

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <string.h>

class BasicAnimal :	public Creature
{
public:
	BasicAnimal();
	BasicAnimal(int, int, int, BasicState*);
	~BasicAnimal();

public:
	Vector2D getVelocity() const { return velocity; }
	void moveAlongVelocity();
	
	virtual void Update() = 0;					//更新状态	
	virtual void AddState(BasicState*) = 0;		//进入新状态
	virtual void FinishCurrentState() = 0;		//完成当前状态

public:
	int generation;
	Creature* destination;
	Vector2D velocity;                    //速度方向
	int changeDirectionFrequence;
	MemorySystem memory;

protected:
	std::stack<BasicState*> statesStack;  //状态堆栈（例如找食物状态途中遇到捕食者，立即将躲避状态压入栈中，安全后将躲避状态弹出栈，继续执行找食物状态）

protected:
	Creature* fakeDestination;
	void getClosest(pathInfo&);
	bool arrive(pathInfo&);
	int distance(Location&, Location&);
	void findRoad(std::list<pathInfo>&);
	bool canVisit(Location&);
	bool isVisitedAndUpdate(std::priority_queue<pathInfo, std::vector<pathInfo>, cmp>&, std::list<pathInfo>&, Location&, pathInfo&, Creature*);
	int getMin(int, int);
    void makeVelocityMovable();

public:
	std::priority_queue<pathInfo, std::vector<pathInfo>, cmp> basicAnimal_Visited;
	std::list<pathInfo> basicAnimal_Finished;

};

#endif

