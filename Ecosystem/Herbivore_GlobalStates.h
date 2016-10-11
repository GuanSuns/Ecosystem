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
	virtual void Execute(Creature*);		//更新状态
	virtual void Resume(Creature*);
	virtual void Exit(Creature*);

	static Herbivore_GlobalStates* getInstance();

protected:
	virtual bool IsInDanger(Herbivore*);		//检查周边环境是否安全
	virtual bool IsSurvive(Herbivore*);		//检查健康指数

private:
	std::vector<Info*> receiver;


};

#endif

