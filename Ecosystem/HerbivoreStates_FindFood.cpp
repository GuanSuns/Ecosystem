#include "HerbivoreStates_FindFood.h"

#include "Herbivore.h"

HerbivoreStates_FindFood::HerbivoreStates_FindFood()
{
}


HerbivoreStates_FindFood::~HerbivoreStates_FindFood()
{
}

void HerbivoreStates_FindFood::Enter(Creature* pCreature)
{
	std::cout << "Test :" << "Herbivore State Find Food\n";

	if (pCreature == nullptr) return;

	Herbivore* creature = (Herbivore*)pCreature;

	if (creature->destination == nullptr)
	{
		std::vector<Info*> infoVector;
		std::vector<MemoryItem> memoryVector;
		infoDispatchMachine.getInfo(infoVector, creature->getGroup(), InfoDispatchMachine::infoType_Food);
		creature->memory.getMemory(memoryVector, MemorySystem::memoryType_Food);

		if (!infoVector.empty())
		{
			Creature* destination = getDestination(infoVector, creature);
			if (destination->IsDead() == true)
			{
				creature->destination = nullptr;
				creature->moveAlongVelocity();
			}
			else
			{
				creature->destination = destination;
			}
		}
		else if (!memoryVector.empty())
		{
			Creature* destinationMemory = getDestinationFromMemory(memoryVector, creature);
			creature->destination = destinationMemory;
		}
		else
		{
			creature->moveAlongVelocity();
		}
	}
}

void HerbivoreStates_FindFood::Execute(Creature* pCreature)
{
	if (pCreature == nullptr) return;

	Herbivore* creature = (Herbivore*)pCreature;
	if (creature->destination == nullptr)
	{
		Enter(creature);
		return;
	}

	std::cout << "Herbivore Finding food\n";

	//this->findFood_Visited.clear();

	memset(mapFlag, 0, sizeof(mapFlag));

	while (!findFood_Visited.empty())  findFood_Visited.pop();

	this->findFood_Finished.clear();
	Location tempLocation;
	pathInfo tempPath;

	tempLocation.x = (creature->location).x;
	tempLocation.y = (creature->location).y;
	tempPath.distance = 0;
	tempPath.pace = 0;
	tempPath.father.x = tempPath.location.x = tempLocation.x;
	tempPath.father.y = tempPath.location.y = tempLocation.y;

	findFood_Visited.push(tempPath);

	mapFlag[tempPath.location.x][tempPath.location.y] = 1;

	while (!findFood_Visited.empty())
	{
		getClosest(tempPath);

		findFood_Finished.push_back(tempPath);

		mapFlag[tempPath.location.x][tempPath.location.y] = 2;

		if (arrive(tempPath, creature))
		{
			findRoad(this->findFood_Finished, creature);
			break;
		}
		else
		{
			for (int j = 0; j < 8; j++)
			{
				tempLocation.x = (tempPath.location).x + MapParameters::moveX[j];
				tempLocation.y = (tempPath.location).y + MapParameters::moveY[j];
				MapParameters::Mod(tempLocation);

				if (canVisit(tempLocation))
				{
					if (!isVisitedAndUpdate(this->findFood_Visited, this->findFood_Finished, tempLocation, tempPath, creature->destination))
					{
						pathInfo pushPath;
						pushPath.location.x = tempLocation.x;
						pushPath.location.y = tempLocation.y;
						pushPath.father.x = (tempPath.location).x;
						pushPath.father.y = (tempPath.location).y;
						pushPath.pace = tempPath.pace + 1;
						pushPath.distance = tempPath.distance + 1 + getDistance(pushPath.location, creature->destination->location) * Parameters::getACoefficient();
						findFood_Visited.push(pushPath);
					}
				}
			}

		}
	}

}

void HerbivoreStates_FindFood::Resume(Creature* pCreature)
{
	return;
}

void HerbivoreStates_FindFood::Exit(Creature* pCreature)
{
	if (pCreature == nullptr) return;

	Herbivore* creature = (Herbivore*)pCreature;
	MemoryItem newMemory;

	creature->modifyHealth(Parameters::getNutrition(creature->destination->getSpeciesID()));
	creature->destination->Die();

	newMemory.memoryDestination = creature->destination;
	newMemory.memoryType = MemorySystem::memoryType_Food;
	creature->memory.UpLoadMemory(newMemory);

	creature->destination = nullptr;

	std::cout << "Herbivore Get Food" << creature->getHealth() << std::endl;

	creature->FinishCurrentState();
	return;
}

bool HerbivoreStates_FindFood::canVisit(Location& testLocation)
{
	return Map[testLocation.x][testLocation.y].animal == nullptr
		&& (Map[testLocation.x][testLocation.y].plant == nullptr || (Map[testLocation.x][testLocation.y].plant)->getSpeciesID() != Parameters::paraWater::speciesID)
		;
}

bool HerbivoreStates_FindFood::isVisitedAndUpdate(std::priority_queue<pathInfo, std::vector<pathInfo>, cmp>& pathList_visited, std::list<pathInfo>& pathList_finished, Location& testLocation, pathInfo& fatherInfo, Creature* destination)
{
	if (mapFlag[testLocation.x][testLocation.y] == 2) return true;
	else return false;
	/*
	std::list<pathInfo>::reverse_iterator it = pathList_finished.rbegin();

	for (; it != pathList_finished.rend(); it++)
	{
		if ((*it).location.x == testLocation.x
			&& (*it).location.y == testLocation.y
			)
			return true;
	}

	it = pathList_visited.rbegin();
	for (; it != pathList_visited.rend(); it++)
	{
		if ((*it).location.x == testLocation.x
			&& (*it).location.y == testLocation.y
			)
		{
			if ((*it).distance > fatherInfo.distance + 1 + getDistance((*it).location, destination->location)*Parameters::getACoefficient())
			{
				(*it).distance = fatherInfo.distance + 1 + getDistance((*it).location, destination->location)*Parameters::getACoefficient();
				(*it).father.x = fatherInfo.location.x;
				(*it).father.y = fatherInfo.location.y;
				(*it).pace = fatherInfo.pace + 1;
			}
			return true;
		}
	}
	return false;
	*/
}

void HerbivoreStates_FindFood::getClosest(pathInfo& tempPath)
{
	if (findFood_Visited.empty()) return;

	while (1)
	{
		if (findFood_Visited.empty()) return;

		if (mapFlag[(findFood_Visited.top()).location.x][(findFood_Visited.top()).location.y] == 2)
		{
			findFood_Visited.pop();
		}
		else
		{
			break;
		}
	}

	tempPath.distance = (findFood_Visited.top()).distance;
	tempPath.location.x = (findFood_Visited.top()).location.x;
	tempPath.location.y = (findFood_Visited.top()).location.y;
	tempPath.father.x = (findFood_Visited.top()).father.x;
	tempPath.father.y = (findFood_Visited.top()).father.y;
	tempPath.pace = (findFood_Visited.top()).pace;

	findFood_Visited.pop();

	return;
	/*
	std::list<pathInfo>::iterator it = pathList.begin();
	std::list<pathInfo>::iterator closest = pathList.begin();

	for (; it != pathList.end(); it++)
	{
		if ((*it).distance < (*closest).distance) closest = it;
	}

	tempPath.distance = (*closest).distance;
	tempPath.location.x = (*closest).location.x;
	tempPath.location.y = (*closest).location.y;
	tempPath.father.x = (*closest).father.x;
	tempPath.father.y = (*closest).father.y;
	tempPath.pace = (*closest).pace;

	pathList.erase(closest);
	*/
}

bool HerbivoreStates_FindFood::arrive(pathInfo& currentLocation, Herbivore* finder)
{
	Creature* destination = finder->destination;
	return (currentLocation.location.x == (destination->location).x && currentLocation.location.y == (destination->location).y)
		|| Map[currentLocation.location.x][currentLocation.location.y].plant == destination
		|| currentLocation.pace >= Parameters::getSpeed(finder->getSpeciesID())
		|| getDistance(currentLocation.location, finder->location) >= Parameters::getEyesight(finder->getSpeciesID());
}

int HerbivoreStates_FindFood::getDistance(Location& l1, Location& l2)
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


int HerbivoreStates_FindFood::getMin(int a, int b)
{
	if (a > b) return b;
	else return a;
}


void HerbivoreStates_FindFood::findRoad(std::list<pathInfo>& pathList, Herbivore* finder)
{
	std::list<pathInfo>::reverse_iterator it = pathList.rbegin();

	if (Map[(*it).location.x][(*it).location.y].plant == finder->destination)
	{
		Exit(finder);
		Map[(*it).location.x][(*it).location.y].animal = finder;
		Map[(*it).location.x][(*it).location.y].plant = nullptr;
		Map[(finder->location).x][(finder->location).y].animal = nullptr;
		(finder->location).x = (*it).location.x;
		(finder->location).y = (*it).location.y;
	}
	else
	{
		Map[(*it).location.x][(*it).location.y].animal = finder;
		Map[(finder->location).x][(finder->location).y].animal = nullptr;
		(finder->location).x = (*it).location.x;
		(finder->location).y = (*it).location.y;
	}
}

Creature* HerbivoreStates_FindFood::getDestination(std::vector<Info*>& infoVector, Herbivore* finder)
{
	int d, mini;

	d = getDistance(infoVector[0]->observed->location, finder->location);
	mini = 0;
	int cnt = infoVector.size();

	for (int i = 1; i < cnt; i++)
	{
		if (getDistance(infoVector[i]->observed->location, finder->location) < d)
		{
			mini = i;
			d = getDistance(infoVector[i]->observed->location, finder->location);
		}
	}
	return infoVector[mini]->observed;
}



Creature* HerbivoreStates_FindFood::getDestinationFromMemory(std::vector<MemoryItem>& infoVector, Herbivore* finder)
{
	int d, mini;

	d = getDistance(infoVector[0].memoryDestination->location, finder->location);
	mini = 0;
	int cnt = infoVector.size();

	for (int i = 1; i < cnt; i++)
	{
		if (getDistance(infoVector[i].memoryDestination->location, finder->location) < d && infoVector[i].memoryDestination->IsDead() == false)
		{
			mini = i;
			d = getDistance(infoVector[i].memoryDestination->location, finder->location);
		}
	}
	return infoVector[mini].memoryDestination;
}


HerbivoreStates_FindFood* HerbivoreStates_FindFood::Instance()
{
	static HerbivoreStates_FindFood herbivoreStates_findFood_instance;
	return &herbivoreStates_findFood_instance;
}
