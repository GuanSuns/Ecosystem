#include "Herbivore.h"


Herbivore::Herbivore()
	:BasicAnimal()
{
}

Herbivore::Herbivore(int speciesID, int LocationX, int LocationY, BasicState* pGlobalState)
	:BasicAnimal( speciesID, LocationX, LocationY, pGlobalState)
{
	statesStack.push(HerbivoreStates_AtRest::Instance());
}

Herbivore::~Herbivore()
{
}

void Herbivore::Born(int n)
{
	if (n <= 0) return;

	Location tempLocation((this->location).x, (this->location).y);
	herbivore_VisitedPoint.clear();
	std::list<Location>::iterator it;
	herbivore_VisitedPoint.push_back(tempLocation);

	memset(mapFlag, 0, sizeof(mapFlag));
	mapFlag[(this->location).x][(this->location).y] = 1;

	int cnt = 0;
	while (cnt < n && (!herbivore_VisitedPoint.empty()))
	{
		it = herbivore_VisitedPoint.begin();
		//std::cout << "Test Herbivore Born Visited Point:" << (*it).x << " , " << (*it).y << std::endl;

		for (int j = 0; j < 8 && cnt < n; j++)
		{
			tempLocation.x = (*it).x + MapParameters::moveX[j];
			tempLocation.y = (*it).y + MapParameters::moveY[j];
			MapParameters::Mod(tempLocation);

			//std::cout << "Inside" << std::endl;

			if (distance(tempLocation, this->location) > distance((*it), this->location)
				&& (!isVisited(herbivore_VisitedPoint, tempLocation))
				&& (Map[tempLocation.x][tempLocation.y].plant == nullptr
				|| (Map[tempLocation.x][tempLocation.y].plant)->getSpeciesID() != Parameters::paraWater::speciesID)
				)
			{
				//std::cout << "Inside 2" << std::endl;
				herbivore_VisitedPoint.push_back(tempLocation);

				mapFlag[tempLocation.x][tempLocation.y] = 1;

				if (Map[tempLocation.x][tempLocation.y].animal == nullptr)
				{
					cnt++;
					
					std::cout << "Herbivore Born:" <<" , "<< tempLocation.x << " , " << tempLocation.y << std::endl;
					
					Herbivore* herbivore = new Herbivore(this->getSpeciesID(), tempLocation.x, tempLocation.y, Herbivore_GlobalStates::getInstance());

					herbivore->memory.copyMemory(this->memory);

					mCreatureVector.Add(herbivore);
				}

			}
		}

		herbivore_VisitedPoint.pop_front();
	}
}

void Herbivore::AddState(BasicState* pState)
{
	if (!statesStack.empty())
	{
		if (pState == statesStack.top()) return;
	}
    statesStack.push(pState);
	pState->Enter(this);

}

void Herbivore::FinishCurrentState()
{
	//std::cout << "Finish\n";
	BasicState* state;
	statesStack.pop();
	state = (statesStack.top());
	state->Resume(this);
}

void Herbivore::Die()
{
	std::cout << "Herbivore Die\n";
	Map[this->location.x][this->location.y].animal = nullptr;
	this->isDead = true;
	return;
}

void Herbivore::Update()
{
	if (isDead == true) return;

	pGlobalState->Execute(this);
	if (isDead == true) return;

	BasicState* pCurrentState = nullptr;

	if (!(this->statesStack).empty())
	{
		pCurrentState = (this->statesStack).top();
		pCurrentState->Execute(this);
	}
	return;
}

bool Herbivore::isVisited(std::list<Location>& mList, Location& mLocation)
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

inline int Herbivore::getCnt(int cnt)
{
	int n = (int)((sqrt((double)cnt + 1.0) + 1.0) / 2.0);
	return (24 * n - 48);
}

bool Herbivore::add(Creature* creature)
{
	if (Map[creature->location.x][creature->location.y].animal == nullptr)
	{
		Map[creature->location.x][creature->location.y].animal = creature;
		return true;
	}
	else
	{
		return false;
	}
}
