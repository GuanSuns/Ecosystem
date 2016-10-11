#ifndef HERBIVORE_GLOBAL_STATES_H
#define HERBIVORE_GLOBAL_STATES_H

#include "BasicState.h"
#include "MapItem.h"
#include "Parameters.h"
#include "InfoDispatchMachine.h"
#include "HerbivoreStates_Escape.h"

class Creature;
class Herbivore;

class Herbivore_GlobalStates : public BasicState
{
public:
	Herbivore_GlobalStates();
	~Herbivore_GlobalStates();

public:
	virtual void Enter(Creature*);
	virtual void Execute(Creature*);		//����״̬
	virtual void Resume(Creature*);
	virtual void Exit(Creature*);

	static Herbivore_GlobalStates* getInstance();

protected:
	virtual bool IsInDanger(Herbivore*);		//����ܱ߻����Ƿ�ȫ
	virtual bool IsSurvive(Herbivore*);		//��齡��ָ��

private:
	std::vector<Info*> receiver;


};

#endif

