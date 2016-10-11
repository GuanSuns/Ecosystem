#include "HerbivoreStates_Escape.h"

#include "Herbivore.h"


HerbivoreStates_Escape::HerbivoreStates_Escape()
{
}


HerbivoreStates_Escape::~HerbivoreStates_Escape()
{
}

void HerbivoreStates_Escape::Enter(Creature* pCreature)
{
	return;
}

void HerbivoreStates_Escape::Execute(Creature* pCreature)
{
	std::cout << "Test :" << "Herbivore State Escape\n";

	if (pCreature == nullptr) return;

	Herbivore* creature = (Herbivore*)pCreature;
	std::vector<Info*> infoVector;
	infoDispatchMachine.getInfo(infoVector, creature->getGroup(), InfoDispatchMachine::infoType_Danger);

	if (infoVector.empty())
	{
		Exit(creature);
		creature->FinishCurrentState();
		return;
	}

	Vector2D escapeDirection(0, 0);
	int cnt = infoVector.size();

	for (int i = 0; i < cnt; i++)
	{
		Vector2D tempVector(infoVector[i]->observed->location, creature->location);
		tempVector.getNormalization();
		tempVector = tempVector * (double)Parameters::getSpeed(infoVector[i]->observed->getSpeciesID());
		tempVector = tempVector / (double)getDistance(infoVector[i]->observed->location, creature->location);
		escapeDirection = escapeDirection + tempVector;
	}
	creature->velocity.setX(escapeDirection.getX());
	creature->velocity.setY(escapeDirection.getY());

	creature->moveAlongVelocity();
	return;
}

void HerbivoreStates_Escape::Resume(Creature* pCreature)
{
	return;
}

void HerbivoreStates_Escape::Exit(Creature* creature)
{
	//std::cout << "Test: Exit Escape" << std::endl;
	return;
}

int HerbivoreStates_Escape::getDistance(Location& l1, Location& l2)
{
	int maxX, maxY, minX, minY, tempX, tempY;
	if (l1.x > l2.x)
	{
		maxX = l1.x;
		minX = l2.x;
	}
	else
	{
		maxX = l2.x;
		minX = l1.x;
	}
	if (l1.y > l2.y)
	{
		maxY = l1.y;
		minY = l2.y;
	}
	else
	{
		maxY = l2.y;
		minY = l1.y;
	}
	tempX = abs(0 - minX) + abs(MapParameters::maxMapHeight - maxX);
	tempY = abs(0 - minY) + abs(MapParameters::maxMapWidth - maxY);

	tempX = getMin(abs(l1.x - l2.x), tempX);
	tempY = getMin(abs(l1.y - l2.y), tempY);

	return tempX + tempY;
}

int HerbivoreStates_Escape::getMin(int a, int b)
{
	if (a > b) return b;
	else return a;
}


HerbivoreStates_Escape* HerbivoreStates_Escape::Instance()
{
	static HerbivoreStates_Escape herbivoreStates_escape_instance;
	return &herbivoreStates_escape_instance;
}