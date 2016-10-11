#include "Herbivore_GlobalStates.h"

#include "Herbivore.h"


Herbivore_GlobalStates::Herbivore_GlobalStates()
{
}


Herbivore_GlobalStates::~Herbivore_GlobalStates()
{
}

void Herbivore_GlobalStates::Enter(Creature* pHerbivore)
{
	return;
}

void Herbivore_GlobalStates::Resume(Creature* pHerbivore)
{
	return;
}

void Herbivore_GlobalStates::Exit( Creature* pHerbivore)
{
	return;
}

void Herbivore_GlobalStates::Execute(Creature* pHerbivore)
{
	Herbivore* herbivore = (Herbivore*)pHerbivore;

	if (herbivore->IsDead() == true)
	{
		return;
	}
	if (!IsSurvive(herbivore))
	{
		//std::cout << "Die\n";
		herbivore->Die();
		return;
	}
	if (IsInDanger(herbivore))
	{
		herbivore->AddState(HerbivoreStates_Escape::Instance());
		return;
	}
	return;
}

bool Herbivore_GlobalStates::IsInDanger(Herbivore* herbivore)
{
	receiver.clear();
	infoDispatchMachine.getInfo(receiver, herbivore->getGroup(), InfoDispatchMachine::infoType_Danger);
	
	if (!receiver.empty()) return true;
	return false;
}

bool Herbivore_GlobalStates::IsSurvive(Herbivore* herbivore)
{
	herbivore->modifyHealth(-(Parameters::getLifeExpenseHealth(herbivore->getSpeciesID())));
	herbivore->modifyThirst(Parameters::getLifeExpenseWater(herbivore->getSpeciesID()));
	herbivore->generation++;
	
	if (herbivore->getHealth() <= 0) return false;
	if (herbivore->getThirst() >= Parameters::getMaxThirst(herbivore->getSpeciesID())) return false;
	if (herbivore->generation >= Parameters::getDeath(herbivore->getSpeciesID())) return false;
	else return true;
}

Herbivore_GlobalStates* Herbivore_GlobalStates::getInstance()
{
	static Herbivore_GlobalStates instance;
	return &instance;
}

