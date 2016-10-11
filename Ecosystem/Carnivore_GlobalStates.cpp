#include "Carnivore_GlobalStates.h"

#include "Carnivore.h"
#include "Creature.h"


Carnivore_GlobalStates::Carnivore_GlobalStates()
{
}


Carnivore_GlobalStates::~Carnivore_GlobalStates()
{
}

void Carnivore_GlobalStates::Enter(Creature* pCarnivore)
{
	return;
}

void Carnivore_GlobalStates::Resume(Creature* pCarnivore)
{
	return;
}

void Carnivore_GlobalStates::Exit(Creature* pCarnivore)
{
	return;
}

void Carnivore_GlobalStates::Execute(Creature* pCarnivore)
{
	Carnivore* carnivore = (Carnivore*)pCarnivore;
	if (carnivore->IsDead() == true)
	{
		return;
	}
	if (!IsSurvive(carnivore))
	{
		//std::cout << "Die\n";
		carnivore->Die();
		return;
	}
	if (IsInDanger(carnivore))
	{
		carnivore->AddState(CarnivoreStates_Escape::Instance());
		return;
	}
	return;
}

bool Carnivore_GlobalStates::IsInDanger(Carnivore* carnivore)
{
	/*
	receiver.clear();
	infoDispatchMachine.getInfo(receiver, carnivore->getGroup(), InfoDispatchMachine::infoType_Danger);

	if (!receiver.empty()) return true;
	*/
	return false;
}

bool Carnivore_GlobalStates::IsSurvive(Carnivore* carnivore)
{
	carnivore->modifyHealth(-(Parameters::getLifeExpenseHealth(carnivore->getSpeciesID())));
	carnivore->modifyThirst(Parameters::getLifeExpenseWater(carnivore->getSpeciesID()));
	carnivore->generation++;

	if (carnivore->getHealth() <= 0) return false;
	if (carnivore->getThirst() >= Parameters::getMaxThirst(carnivore->getSpeciesID())) return false;
	if (carnivore->generation >= Parameters::getDeath(carnivore->getSpeciesID())) return false;
	else return true;
}

Carnivore_GlobalStates* Carnivore_GlobalStates::getInstance()
{
	static Carnivore_GlobalStates instance;
	return &instance;
}
