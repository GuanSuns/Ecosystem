#include "CarnivoreStates_FindFood.h"

#include "Carnivore.h"

CarnivoreStates_FindFood::CarnivoreStates_FindFood()
{
}


CarnivoreStates_FindFood::~CarnivoreStates_FindFood()
{
}

void CarnivoreStates_FindFood::Enter(Creature* pCreature)
{
	std::cout << "Test :" << "Carnivore State Find Food Destination\n";

	if (pCreature == nullptr) return;

	Carnivore* creature = (Carnivore*)pCreature;

	if (creature->destination == nullptr)
	{
		std::vector<Info*> infoVector;
		infoDispatchMachine.getInfo(infoVector, creature->getGroup(), InfoDispatchMachine::infoType_Food);
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
		else
		{
			creature->moveAlongVelocity();
		}
	}
}

void CarnivoreStates_FindFood::Execute(Creature* pCreature)
{
	if (pCreature == nullptr) return;

	Carnivore* creature = (Carnivore*)pCreature;
	if (creature->destination == nullptr || creature->destination->IsDead() == true)
	{
		creature->destination = nullptr;
		Enter(creature);
		return;
	}

	std::cout << "Carnivore Finding food\n";

	memset(mapFlag, 0, sizeof(mapFlag));
	
	while (!findFood_Visited.empty())  findFood_Visited.pop();

	findFood_Finished.clear();

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

				if (canVisit(tempLocation,creature))
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

void CarnivoreStates_FindFood::Resume(Creature* pCreature)
{
	return;
}

void CarnivoreStates_FindFood::Exit(Creature* pCreature)
{
	if (pCreature == nullptr) return;

	Carnivore* creature = (Carnivore*)pCreature;

	creature->modifyHealth(Parameters::getNutrition(creature->destination->getSpeciesID()) - Parameters::getPreyCost(creature->destination->getSpeciesID()) + Parameters::getPreyAbility(creature->getSpeciesID()));
	creature->destination = nullptr;

	std::cout << "Carnivore Get Food" << creature->getHealth() << std::endl;

	creature->FinishCurrentState();
	return;
}

bool CarnivoreStates_FindFood::canVisit(Location& testLocation, Carnivore* finder)
{
	return (Map[testLocation.x][testLocation.y].animal == nullptr || Map[testLocation.x][testLocation.y].animal == finder->destination)
		&& (Map[testLocation.x][testLocation.y].plant == nullptr || (Map[testLocation.x][testLocation.y].plant)->getSpeciesID() != Parameters::paraWater::speciesID)
		;
}

bool CarnivoreStates_FindFood::isVisitedAndUpdate(std::priority_queue<pathInfo, std::vector<pathInfo>, cmp>& pathList_visited, std::list<pathInfo>& pathList_finished, Location& testLocation, pathInfo& fatherInfo, Creature* destination)
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

void CarnivoreStates_FindFood::getClosest(pathInfo& tempPath)
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

bool CarnivoreStates_FindFood::arrive(pathInfo& currentLocation, Carnivore* finder)
{
	Creature* destination = finder->destination;
	return (currentLocation.location.x == (destination->location).x && currentLocation.location.y == (destination->location).y)
		|| Map[currentLocation.location.x][currentLocation.location.y].animal == destination
		|| currentLocation.pace >= Parameters::getSpeed(finder->getSpeciesID())
		|| getDistance(currentLocation.location, finder->location) >= Parameters::getEyesight(finder->getSpeciesID());
}

int CarnivoreStates_FindFood::getDistance(Location& l1, Location& l2)
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


int CarnivoreStates_FindFood::getMin(int a, int b)
{
	if (a > b) return b;
	else return a;
}


void CarnivoreStates_FindFood::findRoad(std::list<pathInfo>& pathList, Carnivore* finder)
{
	std::list<pathInfo>::reverse_iterator it = pathList.rbegin();

	//std::cout << "Get Food\n";

	if (Map[(*it).location.x][(*it).location.y].animal == finder->destination)
	{
		if (finder->getHealth() < Parameters::getPreyCost(finder->destination->getSpeciesID()) - Parameters::getPreyAbility(finder->getSpeciesID()))
		{
			finder->Die();
		}
		else
		{
			finder->destination->Die();
			Map[(*it).location.x][(*it).location.y].animal = finder;
			Map[(finder->location).x][(finder->location).y].animal = nullptr;
			(finder->location).x = (*it).location.x;
			(finder->location).y = (*it).location.y;
			Exit(finder);
		}
		return;
	}
	else
	{
		Map[(*it).location.x][(*it).location.y].animal = finder;
		Map[(finder->location).x][(finder->location).y].animal = nullptr;
		(finder->location).x = (*it).location.x;
		(finder->location).y = (*it).location.y;
	}
		
}

Creature* CarnivoreStates_FindFood::getDestination(std::vector<Info*>& infoVector, Carnivore* finder)
{
	int d, mini;

	d = getDistance(infoVector[0]->observed->location, finder->location);
	mini = 0;
	int cnt = infoVector.size();

	for (int i = 1; i < cnt; i++)
	{
		if (getDistance(infoVector[i]->observed->location, finder->location) < d && infoVector[i]->observed->IsDead() == false)
		{
			mini = i;
			d = getDistance(infoVector[i]->observed->location, finder->location);
		}
	}
	return infoVector[mini]->observed;
}


CarnivoreStates_FindFood* CarnivoreStates_FindFood::Instance()
{
	static CarnivoreStates_FindFood CarnivoreStates_findFood_instance;
	return &CarnivoreStates_findFood_instance;
}

