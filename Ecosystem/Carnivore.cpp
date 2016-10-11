#include "Carnivore.h"


Carnivore::Carnivore()
	:BasicAnimal()
{
}

Carnivore::Carnivore(int speciesID, int LocationX, int LocationY, BasicState* pGlobalState)
	: BasicAnimal(speciesID, LocationX, LocationY, pGlobalState)
{
	statesStack.push(CarnivoreStates_AtRest::Instance());
}

Carnivore::~Carnivore()
{
}

void Carnivore::Born(int n)
{
	if (n <= 0) return;

	Location tempLocation((this->location).x, (this->location).y);
	carnivore_VisitedPoint.clear();
	std::list<Location>::iterator it;
	carnivore_VisitedPoint.push_back(tempLocation);

	memset(mapFlag, 0, sizeof(mapFlag));
	mapFlag[(this->location).x][(this->location).y] = 1;

	int cnt = 0;
	while (cnt < n && (!carnivore_VisitedPoint.empty()))
	{
		it = carnivore_VisitedPoint.begin();
		//std::cout << "Test Carnivore Born Visited Point:" << (*it).x << " , " << (*it).y << std::endl;

		for (int j = 0; j < 8 && cnt < n; j++)
		{
			tempLocation.x = (*it).x + MapParameters::moveX[j];
			tempLocation.y = (*it).y + MapParameters::moveY[j];
			MapParameters::Mod(tempLocation);

			//std::cout << "Inside" << std::endl;

			if (distance(tempLocation, this->location) > distance((*it), this->location)
				&& (!isVisited(carnivore_VisitedPoint, tempLocation))
				&& (Map[tempLocation.x][tempLocation.y].plant == nullptr
				|| (Map[tempLocation.x][tempLocation.y].plant)->getSpeciesID() != Parameters::paraWater::speciesID)
				)
			{
				//std::cout << "Inside 2" << std::endl;
				carnivore_VisitedPoint.push_back(tempLocation);

				mapFlag[tempLocation.x][tempLocation.y] = 1;

				if (Map[tempLocation.x][tempLocation.y].animal == nullptr)
				{
					cnt++;
					
					std::cout << "Carnivore Born:" << " , " << tempLocation.x << " , " << tempLocation.y << std::endl;
					
					Carnivore* carnivore = new Carnivore(this->getSpeciesID(), tempLocation.x, tempLocation.y, Carnivore_GlobalStates::getInstance());

					carnivore->memory.copyMemory(this->memory);

					mCreatureVector.Add(carnivore);
				}

			}
		}

		carnivore_VisitedPoint.pop_front();
	}
}

void Carnivore::AddState(BasicState* pState)
{
	if (!statesStack.empty())
	{
		if (pState == statesStack.top()) return;
	}
	pState->Enter(this);
	statesStack.push(pState);
}

void Carnivore::FinishCurrentState()
{
	//std::cout << "Finish\n";
	BasicState* state;
	statesStack.pop();
	state = (statesStack.top());
	state->Resume(this);
}

void Carnivore::Die()
{
	std::cout << "Carnivore Die\n";
	Map[this->location.x][this->location.y].animal = nullptr;
	this->isDead = true;
	return;
}

void Carnivore::Update()
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

bool Carnivore::isVisited(std::list<Location>& mList, Location& mLocation)
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

inline int Carnivore::getCnt(int cnt)
{
	int n = (int)((sqrt((double)cnt + 1.0) + 1.0) / 2.0);
	return (24 * n - 48);
}

bool Carnivore::add(Creature* creature)
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

