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
	
	virtual void Update() = 0;					//����״̬	
	virtual void AddState(BasicState*) = 0;		//������״̬
	virtual void FinishCurrentState() = 0;		//��ɵ�ǰ״̬

public:
	int generation;
	Creature* destination;
	Vector2D velocity;                    //�ٶȷ���
	int changeDirectionFrequence;
	MemorySystem memory;

protected:
	std::stack<BasicState*> statesStack;  //״̬��ջ��������ʳ��״̬;��������ʳ�ߣ����������״̬ѹ��ջ�У���ȫ�󽫶��״̬����ջ������ִ����ʳ��״̬��

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

