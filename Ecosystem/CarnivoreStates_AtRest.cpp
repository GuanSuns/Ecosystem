#include "CarnivoreStates_AtRest.h"
#include "Carnivore.h"

CarnivoreStates_AtRest::CarnivoreStates_AtRest()
{
}


CarnivoreStates_AtRest::~CarnivoreStates_AtRest()
{
}

void CarnivoreStates_AtRest::Enter(Creature* pCreature)
{
	return;
}

void CarnivoreStates_AtRest::Execute(Creature* pCreature)
{

	std::cout << "Test :" << "Carnivore State At rest\n";

	if (pCreature == nullptr) return;

	Carnivore* creature = (Carnivore*)pCreature;

	if (((creature->velocity).getX() == 0 && creature->velocity.getY() == 0)
		|| creature->changeDirectionFrequence > Parameters::ChangeDirectionFrequence
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
		creature->AddState(CarnivoreStates_FindWater::Instance());
		return;
	}
	if (IsHungry(creature))
	{
		creature->AddState(CarnivoreStates_FindFood::Instance());
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

void CarnivoreStates_AtRest::Resume(Creature* pCreature)
{
	if (pCreature == nullptr) return;

	Carnivore* creature = (Carnivore*)pCreature;

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

void CarnivoreStates_AtRest::Exit(Creature* pCreature)
{
	return;
}

bool CarnivoreStates_AtRest::IsHungry(Creature* creature)
{
	int temp = (int)((double)Parameters::getMaxHealth(creature->getSpeciesID()) * Parameters::getHungerCoefficient() * random.getRandom(Parameters::getHungerFeelingCoefficient(), 1.0));

	//std::cout << "Test Health:" << creature->getHealth() << "," << temp << "\n";

	return creature->getHealth() < temp;
}

bool CarnivoreStates_AtRest::IsThirsty(Creature* creature)
{
    int temp = (int)((double)Parameters::getMaxThirst(creature->getSpeciesID()) * (1 - Parameters::getHungerCoefficient()) * random.getRandom(Parameters::getHungerFeelingCoefficient(), 1.0));

	//std::cout << "Test Thirst:" << creature->getThirst() << ","<<temp<<"\n";

	return creature->getThirst() > temp;
}

bool CarnivoreStates_AtRest::IsMove(Creature* creature)
{
	return random.getRandom(0, 1.0) < Parameters::getVigour(creature->getSpeciesID());
}

CarnivoreStates_AtRest* CarnivoreStates_AtRest::Instance()
{
	static CarnivoreStates_AtRest CarnivoreStates_AtRest_instance;
	return &CarnivoreStates_AtRest_instance;
}
