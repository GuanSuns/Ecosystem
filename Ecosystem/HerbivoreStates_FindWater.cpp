#include "HerbivoreStates_FindWater.h"

#include "Herbivore.h"

HerbivoreStates_FindWater::HerbivoreStates_FindWater()
{
}


HerbivoreStates_FindWater::~HerbivoreStates_FindWater()
{
}

void HerbivoreStates_FindWater::Enter(Creature* pCreature)
{
	std::cout << "Test :" << "Herbivore State FindWater\n";

	if (pCreature == nullptr) return;


	Herbivore* creature = (Herbivore*)pCreature;
	if (creature->destination == nullptr)
	{
		std::vector<Info*> infoVector;
		std::vector<MemoryItem> memoryVector;
		infoDispatchMachine.getInfo(infoVector, creature->getGroup(), InfoDispatchMachine::infoType_Water);
		creature->memory.getMemory(memoryVector, MemorySystem::memoryType_Water);

		if (!infoVector.empty())
		{
			Creature* destination = getDestination(infoVector, creature);
			creature->destination = destination;
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

void HerbivoreStates_FindWater::Execute(Creature* pCreature)
{
	if (pCreature == nullptr) return;
	
	Herbivore* creature = (Herbivore*)pCreature;
	if (creature->destination == nullptr)
	{
		Enter(creature);
		return;
	}

	std::cout << "Herbivore Test finding water destination : " << creature->destination->location.x << " , " << creature->destination->location.y <<", Thirsty "<<creature->getThirst() <<std::endl;

	memset(mapFlag, 0, sizeof(mapFlag));

	//findWater_Visited.clear();

	while (!findWater_Visited.empty())  findWater_Visited.pop();

	findWater_Finished.clear();
	Location tempLocation;
	pathInfo tempPath;

	tempLocation.x = (creature->location).x;
	tempLocation.y = (creature->location).y;
	tempPath.distance = 0;
	tempPath.pace = 0;
	tempPath.father.x = tempPath.location.x = tempLocation.x;
	tempPath.father.y = tempPath.location.y = tempLocation.y;
	findWater_Visited.push(tempPath);

	while (!findWater_Visited.empty())
	{
		getClosest(tempPath);

		findWater_Finished.push_back(tempPath);

		mapFlag[tempPath.location.x][tempPath.location.y] = 2;

		if ( arrive(tempPath, creature) )
		{			
			findRoad(findWater_Finished, creature);
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
					if (!isVisitedAndUpdate(findWater_Visited, findWater_Finished, tempLocation, tempPath, creature->destination))
					{
						pathInfo pushPath;
						pushPath.location.x = tempLocation.x;
						pushPath.location.y = tempLocation.y;
						pushPath.father.x = (tempPath.location).x;
						pushPath.father.y = (tempPath.location).y;
						pushPath.pace = tempPath.pace+1;
						pushPath.distance = tempPath.distance + 1 + getDistance(pushPath.location, creature->destination->location) * Parameters::getACoefficient();
						findWater_Visited.push(pushPath);
					}
				}
			}
			
		}
	}

}

void HerbivoreStates_FindWater::Resume(Creature* pCreature)
{
	return;
}

void HerbivoreStates_FindWater::Exit(Creature* pCreature)
{
	if (pCreature == nullptr) return;

	Herbivore* creature = (Herbivore*)pCreature;
	MemoryItem newMemory;

	creature->modifyThirst(-Parameters::getNutrition(creature->destination->getSpeciesID()));
	newMemory.memoryDestination = creature->destination;
	newMemory.memoryType = MemorySystem::memoryType_Water;
	creature->memory.UpLoadMemory(newMemory);

	std::cout << "Herbivore Get Water " << creature->getThirst() << std::endl;
	
	creature->destination = nullptr;
	
	creature->FinishCurrentState();
	return;
}

bool HerbivoreStates_FindWater::canVisit(Location& testLocation)
{
	return Map[testLocation.x][testLocation.y].animal == nullptr;		
}

bool HerbivoreStates_FindWater::isVisitedAndUpdate(std::priority_queue<pathInfo, std::vector<pathInfo>, cmp>& pathList_visited, std::list<pathInfo>& pathList_finished, Location& testLocation, pathInfo& fatherInfo, Creature* destination)
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

void HerbivoreStates_FindWater::getClosest(pathInfo& tempPath)
{
	if (findWater_Visited.empty()) return;

	while (1)
	{
		if (findWater_Visited.empty()) return;
		if (mapFlag[(findWater_Visited.top()).location.x][(findWater_Visited.top()).location.y] == 2)
		{
			findWater_Visited.pop();
		}
		else
		{
			break;
		}
	}

	tempPath.distance = (findWater_Visited.top()).distance;
	tempPath.location.x = (findWater_Visited.top()).location.x;
	tempPath.location.y = (findWater_Visited.top()).location.y;
	tempPath.father.x = (findWater_Visited.top()).father.x;
	tempPath.father.y = (findWater_Visited.top()).father.y;
	tempPath.pace = (findWater_Visited.top()).pace;

	findWater_Visited.pop();

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

bool HerbivoreStates_FindWater::arrive(pathInfo& currentLocation, Herbivore* finder)
{
	Creature* destination = finder->destination;
	return (currentLocation.location.x == (destination->location).x && currentLocation.location.y == (destination->location).y)
		|| Map[currentLocation.location.x][currentLocation.location.y].plant == destination
		|| currentLocation.pace >= Parameters::getSpeed(finder->getSpeciesID())
		|| getDistance(currentLocation.location, finder->location) >= Parameters::getEyesight(finder->getSpeciesID());
}


void HerbivoreStates_FindWater::findRoad(std::list<pathInfo>& pathList, Herbivore* finder)
{
	std::list<pathInfo>::reverse_iterator it = pathList.rbegin();

	Map[(*it).location.x][(*it).location.y].animal = finder;
	Map[(finder->location).x][(finder->location).y].animal = nullptr;
	(finder->location).x = (*it).location.x;
	(finder->location).y = (*it).location.y;

	if (Map[(*it).location.x][(*it).location.y].plant == finder->destination)
	{
		Exit(finder);
	}
}

Creature* HerbivoreStates_FindWater::getDestination(std::vector<Info*>& infoVector, Herbivore* finder)
{
	int d,mini;

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

Creature* HerbivoreStates_FindWater::getDestinationFromMemory(std::vector<MemoryItem>& infoVector, Herbivore* finder)
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



HerbivoreStates_FindWater* HerbivoreStates_FindWater::Instance()
{
	static HerbivoreStates_FindWater herbivoreStates_findWater_instance;
	return &herbivoreStates_findWater_instance;
}


int HerbivoreStates_FindWater::getDistance(Location& l1, Location& l2)
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


int HerbivoreStates_FindWater::getMin(int a, int b)
{
	if (a > b) return b;
	else return a;
}


