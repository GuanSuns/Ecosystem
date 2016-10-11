#ifndef CARNIVORE_GLOBAL_STATES_H
#define CARNIVORE_GLOBAL_STATES_H

#include "BasicState.h"
#include "MapItem.h"
#include "Parameters.h"
#include "InfoDispatchMachine.h"
#include "CarnivoreStates_Escape.h"

class Creature;
class Carnivore;

class Carnivore_GlobalStates : public BasicState
{
public:
	Carnivore_GlobalStates();
	~Carnivore_GlobalStates();

public:
	virtual void Enter(Creature*);
	virtual void Execute(Creature*);		//����״̬
	virtual void Resume(Creature*);
	virtual void Exit(Creature*);

	static Carnivore_GlobalStates* getInstance();

protected:
	virtual bool IsInDanger(Carnivore*);		//����ܱ߻����Ƿ�ȫ
	virtual bool IsSurvive(Carnivore*);		//��齡��ָ��

private:
	std::vector<Info*> receiver;


};

#endif

