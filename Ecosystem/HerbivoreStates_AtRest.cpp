#include "HerbivoreStates_AtRest.h"

#include "Herbivore.h"



HerbivoreStates_AtRest::HerbivoreStates_AtRest()
{
}


HerbivoreStates_AtRest::~HerbivoreStates_AtRest()
{
}

void HerbivoreStates_AtRest::Enter(Creature* pCreature)
{
	return;
}

void HerbivoreStates_AtRest::Execute(Creature* pCreature)
{

	std::cout << "Test :" << "Herbivore State At rest\n";

	if (pCreature == nullptr) return;

	Herbivore* creature = (Herbivore*)pCreature;

	if (((creature->velocity).getX() == 0 && creature->velocity.getY() == 0)
		|| creature->changeDirectionFrequence>Parameters::ChangeDirectionFrequence
		)
	{
		(creature->velocity).setX(random.getRandom(0, 20.0));
		(creature->velocity).setY(random.getRandom(0, 20.0));
		double X = (creature->velocity).getX();
		double Y = (creature->velocity).getY();
		X = X - 10.0;
		Y = Y - 10.0;
		(creature->velocity).setX(X);
		(creature->velocity).setY(Y);
		(creature->velocity).getNormalization();

		creature->changeDirectionFrequence = 0;
	}
	
	if (IsThirsty(creature))
	{
		creature->AddState(HerbivoreStates_FindWater::Instance());
		return;
	}
	if (IsHungry(creature))
	{
		creature->AddState(HerbivoreStates_FindFood::Instance());
		return;
	}
	if (IsMove(creature))
	{
		creature->changeDirectionFrequence++;
		creature->moveAlongVelocity();
		return;
	}
	return;
}

void HerbivoreStates_AtRest::Resume(Creature* pCreature)
{
	if (pCreature == nullptr) return;

	Herbivore* creature = (Herbivore*)pCreature;

	(creature->velocity).setX(random.getRandom(0, 20.0));
	(creature->velocity).setY(random.getRandom(0, 20.0));
	double X = (creature->velocity).getX();
	double Y = (creature->velocity).getY();
	X = X - 10.0;
	Y = Y - 10.0;
	(creature->velocity).setX(X);
	(creature->velocity).setY(Y);
	(creature->velocity).getNormalization();

	creature->changeDirectionFrequence = 0;
}

void HerbivoreStates_AtRest::Exit(Creature* pCreature)
{
	return;
}

bool HerbivoreStates_AtRest::IsHungry(Creature* creature)
{
	int temp = (int)((double)Parameters::getMaxHealth(creature->getSpeciesID()) * Parameters::getHungerCoefficient() * random.getRandom(Parameters::getHungerFeelingCoefficient(), 1.0));
	
	//std::cout << "Test Health:" << creature->getHealth() << "," << temp << "\n";
	
	return creature->getHealth() < temp;
}

bool HerbivoreStates_AtRest::IsThirsty(Creature* creature)
{	
    int temp = (int)((double)Parameters::getMaxThirst(creature->getSpeciesID()) * (1-Parameters::getHungerCoefficient()) * random.getRandom(Parameters::getHungerFeelingCoefficient(), 1.0));

	//std::cout << "Test Thirst:" << creature->getThirst() << ","<<temp<<"\n";

	return creature->getThirst() > temp;
}

bool HerbivoreStates_AtRest::IsMove(Creature* creature)
{
	return random.getRandom(0, 1.0) < Parameters::getVigour(creature->getSpeciesID());
}

HerbivoreStates_AtRest* HerbivoreStates_AtRest::Instance()
{
	static HerbivoreStates_AtRest herbivoreStates_atRest_instance;
	return &herbivoreStates_atRest_instance;
}
