#include "CarnivoreStates_Escape.h"

#include "Carnivore.h"

CarnivoreStates_Escape::CarnivoreStates_Escape()
{
}


CarnivoreStates_Escape::~CarnivoreStates_Escape()
{
}

void CarnivoreStates_Escape::Enter(Creature* pCreature)
{
	return;
}

void CarnivoreStates_Escape::Execute(Creature* pCreature)
{
	std::cout << "Test :" << "CarnivoreState Escape\n";

	if (pCreature == nullptr) return;

	Carnivore* creature = (Carnivore*)pCreature;
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

void CarnivoreStates_Escape::Resume(Creature* pCreature)
{
	return;
}

void CarnivoreStates_Escape::Exit(Creature* creature)
{
	//std::cout << "Test: Exit Escape" << std::endl;
	return;
}

int CarnivoreStates_Escape::getDistance(Location& l1, Location& l2)
{
	int maxX, maxY, minX, minY, tempX,tempY;
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

int CarnivoreStates_Escape::getMin(int a, int b)
{
	if (a > b) return b;
	else return a;
}


CarnivoreStates_Escape* CarnivoreStates_Escape::Instance()
{
	static CarnivoreStates_Escape CarnivoreStates_Escape_instance;
	return &CarnivoreStates_Escape_instance;
}