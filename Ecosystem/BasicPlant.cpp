#include "BasicPlant.h"


BasicPlant::BasicPlant()
	:Creature()
{
	groupSize = 1;
}

BasicPlant::BasicPlant(int speciesID, int LocationX, int LocationY, BasicState* pGlobalState)
	:Creature(speciesID, LocationX, LocationY, pGlobalState)
{
	groupSize = 1;
}


BasicPlant::~BasicPlant()
{
}

void BasicPlant::Update()
{
    if(this->getSpeciesID() == Parameters::paraWater::speciesID ) return;

    if (groupSize < 50)
    {
        this->Born(1);
    }
    else if (groupSize < Parameters::maxPlant)
    {
        this->Born(2);
    }
    /*
    else if (groupSize < 1000)
    {
        this->Born(3);
    }
    else
    {
        int addNumber = (int)((double)groupSize*Parameters::getBirthrate(this->getSpeciesID()));
        this->Born(addNumber);
    }
    */
}

void BasicPlant::Die()
{
	groupSize--;
	if (groupSize < 0) groupSize = 0;
}

void BasicPlant::Born(int n)
{
	if (n <= 0) return;

	Location tempLocation((this->location).x, (this->location).y);
	plants_VisitedPoint.clear();
	std::list<Location>::iterator it;
	plants_VisitedPoint.push_back(tempLocation);

	memset(mapFlag, 0, sizeof(mapFlag));
	mapFlag[(this->location).x][(this->location).y] = 1;

	int cnt = 0;
	while (cnt < n && (!plants_VisitedPoint.empty()))
	{
		it = plants_VisitedPoint.begin();
		//std::cout << "Test Herbivore Born Visited Point:" << (*it).x << " , " << (*it).y << std::endl;

		for (int j = 0; j < 8 && cnt < n; j++)
		{
			tempLocation.x = (*it).x + MapParameters::moveX[j];
			tempLocation.y = (*it).y + MapParameters::moveY[j];
			MapParameters::Mod(tempLocation);

			//std::cout << "Inside" << std::endl;

			if (distance(tempLocation, this->location) > distance((*it), this->location)
				&& (!isVisited(plants_VisitedPoint, tempLocation))
				&& (Map[tempLocation.x][tempLocation.y].plant == nullptr || (Map[tempLocation.x][tempLocation.y].plant)->getSpeciesID() != Parameters::paraWater::speciesID)
				)
			{
				//std::cout << "Inside 2" << std::endl;
				plants_VisitedPoint.push_back(tempLocation);

				mapFlag[tempLocation.x][tempLocation.y] = 1;

				if (Map[tempLocation.x][tempLocation.y].plant == nullptr)
				{
					cnt++;
					groupSize++;

                    //std::cout << "Plant Born:" << " , " << tempLocation.x << " , " << tempLocation.y << std::endl;

					Map[tempLocation.x][tempLocation.y].plant = this;
				}

			}
		}

		plants_VisitedPoint.pop_front();
	}
}


bool BasicPlant::isVisited(std::list<Location>& mList, Location& mLocation)
{
	if (mapFlag[mLocation.x][mLocation.y] == 1) return true;
	else return false;
	/*
	int cnt = mList.size();
	int n = getCnt(cnt);

	if (cnt == 0) return false;

	std::list<Location>::reverse_iterator it = mList.rbegin();

	for (int i = 0; i < cnt && (cnt < 48 || i < n); i++)
	{
	if (mLocation.x == (*it).x && mLocation.y == (*it).y)
	{
	//std::cout << "True\n";
	return true;
	}
	it++;
	if (it == mList.rend()) break;
	}
	//std::cout << "False\n";
	return false;
	*/
}


inline int BasicPlant::getCnt(int cnt)
{
	int n = (int)((sqrt((double)cnt + 1.0) + 1.0) / 2.0);
	return (24 * n - 48);
}

bool BasicPlant::add(Creature* creature)
{
	if (Map[creature->location.x][creature->location.y].plant == nullptr)
	{
		Map[creature->location.x][creature->location.y].plant = creature;
		return true;
	}
	else
	{
		return false;
	}
}

int BasicPlant::distance(Location& l1, Location& l2)
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

int BasicPlant::getMin(int a, int b)
{
	if (a > b) return b;
	else return a;
}
