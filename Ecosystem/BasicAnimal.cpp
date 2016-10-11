#include "BasicAnimal.h"


BasicAnimal::BasicAnimal()
	:Creature()
{
	generation = 1;
	this->velocity = Vector2D(0, 0);
	this->destination = nullptr;
	changeDirectionFrequence = 0;
}

BasicAnimal::BasicAnimal(int speciesID, int LocationX, int LocationY, BasicState* pGlobalState)
	:Creature(speciesID, LocationX, LocationY, pGlobalState) 
{
	generation = 1;
	this->velocity = Vector2D(0, 0);
	this->destination = nullptr;
	changeDirectionFrequence = 0;
}


BasicAnimal::~BasicAnimal()
{
}

void BasicAnimal::moveAlongVelocity()
{
	
	if (velocity.getX() == 0 && velocity.getY() == 0)
	{
		velocity.setX(random.getRandom(0, 20.0));
		velocity.setY(random.getRandom(0, 20.0));
		double X = velocity.getX();
		double Y = velocity.getY();
		X = X - 10.0;
		Y = Y - 10.0;
		velocity.setX(X);
		velocity.setY(Y);
	}
	velocity.getNormalization();

    makeVelocityMovable();

	Location desLocation;
	desLocation.x = (int)((double)Parameters::getSpeed(this->getSpeciesID())*velocity.getX()) + (this->location).x;
	desLocation.y = (int)((double)Parameters::getSpeed(this->getSpeciesID())*velocity.getY()) + (this->location).y;
	MapParameters::Mod(desLocation);

    //std::cout << "Move along velocity Test_Destination:" << desLocation.x << "," << desLocation.y << "\n";
	
	if (Map[desLocation.x][desLocation.y].animal != nullptr)
	{
		for (int i = 1; i < 100;i++)
		{
			desLocation.x = (int)((double)desLocation.x + velocity.getX());
            desLocation.y = (int)((double)desLocation.y + velocity.getY());
			MapParameters::Mod(desLocation);

            //std::cout << "Move along velocity Test_Destination : " << desLocation.x << "," << desLocation.y << "\n";

			if (Map[desLocation.x][desLocation.y].animal == nullptr
				&& (Map[desLocation.x][desLocation.y].plant == nullptr || (Map[desLocation.x][desLocation.y].plant)->getSpeciesID() != Parameters::paraWater::speciesID)
				)
				break;
		}
	}


	fakeDestination = new BasicPlant(Parameters::paraWater::speciesID, desLocation.x, desLocation.y, Herbivore_GlobalStates::getInstance());
	
	std::cout << "Animal MoveAlong Velocity Final_Destination:" << desLocation.x << "," << desLocation.y << "\n";

	memset(mapFlag, 0, sizeof(mapFlag));

	//basicAnimal_Visited.clear();

	while (!basicAnimal_Visited.empty())  basicAnimal_Visited.pop();

	
	basicAnimal_Finished.clear();
	Location tempLocation(0, 0);
	pathInfo tempPath;

	tempLocation.x = (this->location).x;
	tempLocation.y = (this->location).y;
	tempPath.distance = 0;
	tempPath.pace = 0;
	tempPath.father.x = tempPath.location.x = tempLocation.x;
	tempPath.father.y = tempPath.location.y = tempLocation.y;
	basicAnimal_Visited.push(tempPath);

	while (!basicAnimal_Visited.empty())
	{
		getClosest(tempPath);
		//std::cout << "Cloest:" << tempPath.location.x<<","<<tempPath.location.y << "  Pace :"<<tempPath.pace<<"\n";
		basicAnimal_Finished.push_back(tempPath);

		mapFlag[tempPath.location.x][tempPath.location.y] = 2;

		if (arrive(tempPath)) 
		{
			//std::cout << "Finished" << "\n";
			findRoad(basicAnimal_Finished);
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
					if (!isVisitedAndUpdate(basicAnimal_Visited, basicAnimal_Finished, tempLocation, tempPath, destination))
					{
						pathInfo pushPath;
						pushPath.location.x = tempLocation.x;
						pushPath.location.y = tempLocation.y;
						pushPath.father.x = (tempPath.location).x;
						pushPath.father.y = (tempPath.location).y;
						pushPath.distance = tempPath.distance + 1 + distance(pushPath.location,this->fakeDestination->location) *Parameters::getACoefficient();
						pushPath.pace = tempPath.pace + 1;
						basicAnimal_Visited.push(pushPath);
					}
				}
			}

		}
	}

}

void BasicAnimal::getClosest(pathInfo& tempPath)
{
	if (basicAnimal_Visited.empty()) return;

	while (1)
	{
		if (basicAnimal_Visited.empty()) return;
		if (mapFlag[(basicAnimal_Visited.top()).location.x][(basicAnimal_Visited.top()).location.y] == 2)
		{
			basicAnimal_Visited.pop();
		}
		else
		{
			break;
		}
	}

	tempPath.distance = (basicAnimal_Visited.top()).distance;
	tempPath.location.x = (basicAnimal_Visited.top()).location.x;
	tempPath.location.y = (basicAnimal_Visited.top()).location.y;
	tempPath.father.x = (basicAnimal_Visited.top()).father.x;
	tempPath.father.y = (basicAnimal_Visited.top()).father.y;
	tempPath.pace = (basicAnimal_Visited.top()).pace;

	basicAnimal_Visited.pop();
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

bool BasicAnimal::arrive(pathInfo& infoPath)
{
	return (infoPath.location.x == (this->fakeDestination->location).x && infoPath.location.y == (this->fakeDestination->location).y)
		|| Map[infoPath.location.x][infoPath.location.y].plant == this->fakeDestination
		|| infoPath.pace >= Parameters::getSpeed(this->getSpeciesID())
		|| distance(infoPath.location, this->location) >= Parameters::getEyesight(this->getSpeciesID());
}

int BasicAnimal::distance(Location& l1, Location& l2)
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

void BasicAnimal::findRoad(std::list<pathInfo>& pathList)
{
	std::list<pathInfo>::reverse_iterator it = pathList.rbegin();

	Map[(*it).location.x][(*it).location.y].animal = this;
	Map[(this->location).x][(this->location).y].animal = nullptr;
	(this->location).x = (*it).location.x;
	(this->location).y = (*it).location.y;
	//std::cout << "Get:" << (*it).location.x << "," << (*it).location.y << "\n";

	delete this->fakeDestination;
	this->fakeDestination = nullptr;
}

bool BasicAnimal::canVisit(Location& testLocation)
{
	return Map[testLocation.x][testLocation.y].animal == nullptr
		&& (Map[testLocation.x][testLocation.y].plant == nullptr
		|| (Map[testLocation.x][testLocation.y].plant)->getSpeciesID() != Parameters::paraWater::speciesID)
		;
}

bool BasicAnimal::isVisitedAndUpdate(std::priority_queue<pathInfo, std::vector<pathInfo>, cmp>& pathList_visited, std::list<pathInfo>& pathList_finished, Location& testLocation, pathInfo& fatherInfo, Creature* destination)
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
			if ((*it).distance > fatherInfo.distance + 1 + distance((*it).location, this->fakeDestination->location) *Parameters::getACoefficient())
			{
				(*it).distance = fatherInfo.distance + 1 + distance((*it).location, this->fakeDestination->location) *Parameters::getACoefficient();
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

int BasicAnimal::getMin(int a, int b)
{
	if (a > b) return b;
    else return a;
}

void BasicAnimal::makeVelocityMovable()
{
    int i = 1;
    double vx = this->velocity.getX();
    double vy = this->velocity.getY();
    double dx = vx;
    double dy = vy;

    for (; i < 100; i++)
    {
        if ((vx != 0 && 0 == (int)(vx*(double)Parameters::getSpeed(this->getSpeciesID())))
            || (vy != 0 && 0 == (int)(vy*(double)Parameters::getSpeed(this->getSpeciesID())))
            )
        {
            vx = vx + dx;
            vy = vy + dy;
        }
        else
        {
            break;
        }
    }

    this->velocity.setX(vx);
    this->velocity.setY(vy);
}


