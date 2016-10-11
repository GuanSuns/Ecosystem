#include "CreatureVector.h"

CreatureVector mCreatureVector;

CreatureVector::CreatureVector()
{
    clearCnt();
}


CreatureVector::~CreatureVector()
{
}

void CreatureVector::Update()
{
	infoDispatchMachine.clearInfo();
    clearCnt();

	UpdateGroup();
	UpdateIndividual();
	
	//if (creatureVector.empty()) std::cout << "Creature Empty\n";

	//std::cout << "Creature Size" << creatureVector.size()<<"\n";

	std::vector<Creature*>::iterator it = creatureVector.begin();

	for (; it != creatureVector.end(); it++)
	{
        if((*it)->getSpeciesID() < 1000 )
        {
            std::cout<<"ID : "<<(*it)->getSpeciesID() <<" Location : " << (*it)->location.x << " , " << (*it)->location.y<<"\n";
        }
	}
	
}

void CreatureVector::UpdateIndividual()
{
	if (creatureVector.empty()) return;

	std::vector<Creature*>::iterator it = creatureVector.begin();
	for (; ; )
	{
		if ((*it)->IsDead() == true)
		{
			delete (*it);
			it = creatureVector.erase(it);
		}
		else
		{
            cntBySpeciesID((*it)->getSpeciesID());

			(*it)->Update();
			(*it)->isUpdated = false;
			it++;
		}

		if (it == creatureVector.end()) break;
	}	
}

void CreatureVector::UpdateGroup()
{
	int groupSize;
	int cntMature;
	if (creatureVector.empty()) return;
	int cnt = creatureVector.size();

	Creature* creature;
	for (int i = 0; i < cnt; i++)
	{
		creature = creatureVector[i];

		if (creature->IsDead() == true) continue;
		if (creature->isUpdated == true) continue;
		if (creature->getSpeciesID() > 1000) continue;   //植物不存在种群交流

		groupMember.clear();

		memset(mapFlag, 0, sizeof(mapFlag));

		creature->isUpdated = true;
		creature->setGroup(creature);
		groupMember.push_back(creature);
		groupSize = 0;
		cntMature = 0;

		while (!groupMember.empty())
		{
			groupSize++;
			Creature* pCreature = groupMember.front();
			pCreature->setGroup(creature);

			BasicAnimal* tempAnimal = (BasicAnimal*)pCreature;
            if (tempAnimal->generation > Parameters::getMinBirthAge(tempAnimal->getSpeciesID()) && tempAnimal->generation < Parameters::getMaxBirthAge(tempAnimal->getSpeciesID())) cntMature++;

			visitedList.clear();			

			UpdateUnit(pCreature, creature);
			groupMember.pop_front();
		}

		if (groupSize >= 5)
		{
			creature->Born((int)(cntMature*Parameters::getBirthrate(creature->getSpeciesID())));
		}
	}

	groupMember.clear();
	visitedList.clear();
}

void CreatureVector::UpdateUnit(Creature* pCreature, Creature* core)
{
	Location tempLocation;

	visitedList.push_back(pCreature->location);

	mapFlag[pCreature->location.x][pCreature->location.y] = 1;

	std::list<Location>::iterator it = visitedList.begin();

	while (1)
	{
		for (int j = 0; j < 8; j++)
		{
			tempLocation.x = (*it).x + MapParameters::moveX[j];
			tempLocation.y = (*it).y + MapParameters::moveY[j];
			MapParameters::Mod(tempLocation);

			if (canVisit(tempLocation, pCreature->location, core->location, pCreature))
			{
				visitedList.push_back(tempLocation);

				mapFlag[tempLocation.x][tempLocation.y] = 1;

				if (Map[tempLocation.x][tempLocation.y].animal != nullptr)
				{
					if ((Map[tempLocation.x][tempLocation.y].animal)->getSpeciesID() == pCreature->getSpeciesID()
						&& (Map[tempLocation.x][tempLocation.y].animal)->isUpdated == false
						&& (Map[tempLocation.x][tempLocation.y].animal)->IsDead() == false
						)
					{
						(Map[tempLocation.x][tempLocation.y].animal)->isUpdated = true;
						(Map[tempLocation.x][tempLocation.y].animal)->setGroup(core);
						groupMember.push_back(Map[tempLocation.x][tempLocation.y].animal);
					}
					else if ((Map[tempLocation.x][tempLocation.y].animal)->IsDead() == false && Parameters::isFood(pCreature->getSpeciesID(), Map[tempLocation.x][tempLocation.y].animal->getSpeciesID()))
					{
						Info* tempInfo = new Info();
						tempInfo->infoType = InfoDispatchMachine::infoType_Food;
						tempInfo->observed = Map[tempLocation.x][tempLocation.y].animal;
						tempInfo->sender = core;
						infoDispatchMachine.UpLoadInfo(tempInfo);
					}
					else if ((Map[tempLocation.x][tempLocation.y].animal)->IsDead() == false && Parameters::isDanger(pCreature->getSpeciesID(), Map[tempLocation.x][tempLocation.y].animal->getSpeciesID()))
					{
						Info* tempInfo = new Info();
						tempInfo->infoType = InfoDispatchMachine::infoType_Danger;
						tempInfo->observed = Map[tempLocation.x][tempLocation.y].animal;
						tempInfo->sender = core;
						infoDispatchMachine.UpLoadInfo(tempInfo);
					}
				}

				if (Map[tempLocation.x][tempLocation.y].plant != nullptr)
				{
					if (Parameters::isFood(pCreature->getSpeciesID(), Map[tempLocation.x][tempLocation.y].plant->getSpeciesID()))
					{
						Info* tempInfo = new Info();
						tempInfo->infoType = InfoDispatchMachine::infoType_Food;
						tempInfo->observed = Map[tempLocation.x][tempLocation.y].plant;
						tempInfo->sender = core;
						infoDispatchMachine.UpLoadInfo(tempInfo);
					}
					if (Map[tempLocation.x][tempLocation.y].plant->getSpeciesID() == Parameters::paraWater::speciesID)
					{
						Info* tempInfo = new Info();
						tempInfo->infoType = InfoDispatchMachine::infoType_Water;
						tempInfo->observed = Map[tempLocation.x][tempLocation.y].plant;
						tempInfo->sender = core;
						infoDispatchMachine.UpLoadInfo(tempInfo);
					}
				}

			}
		}

		it++;
		if (it == visitedList.end()) break;
	}	
}

inline int CreatureVector::distance(Location& l1, Location& l2)
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

inline bool CreatureVector::isVisited(Location& mLocation)
{
	int cnt = visitedList.size();
	int n = getCnt(cnt);
	if (cnt == 0) return false;

	if (mapFlag[mLocation.x][mLocation.y] == 0) return false;
	else return true;

	/*
	std::list<Location>::reverse_iterator it = visitedList.rbegin();

	for (int i = 0; i < cnt && (cnt < 48 || i < n); i++)
	{
		if (mLocation.x == (*it).x && mLocation.y == (*it).y)
		{
			return true;
		}
		it++;
		if (it == visitedList.rend()) break;
	}
	return false;
	*/
}

inline bool CreatureVector::canVisit(Location& desitination, Location& member, Location& core, Creature* creature)
{
	return (distance(desitination, member) < Parameters::getEyesight(creature->getSpeciesID()))
		&& (distance(desitination, core) > distance(member, core))
		&& (!isVisited(desitination)); 
}

inline int CreatureVector::getCnt(int cnt)
{
	int n = (int)((sqrt((double)cnt+1.0)+1.0)/2.0);
    return (24 * n - 48);
}

void CreatureVector::cntBySpeciesID(int ID)
{
    if (ID == Parameters::paraCow::speciesID)
    {
        cntCow++;
    }
    else if (ID == Parameters::paraSheep::speciesID)
    {
        cntSheep++;
    }
    else if (ID == Parameters::paraWolf::speciesID)
    {
        cntWolf++;
    }
    else if (ID == Parameters::paraTiger::speciesID)
    {
        cntTiger++;
    }
}

void CreatureVector::Add(Creature* creature)
{
	if (creature != nullptr && creature->add(creature) == true)
	{
		creatureVector.push_back(creature);
	}
	else
	{
		delete creature;
	}
}

void CreatureVector::Add(Creature* creature, int n)
{
	if (creature != nullptr&& creature->add(creature) == true)
	{
		creatureVector.push_back(creature);
		creature->Born(n-1);
	}
	else
	{
		delete creature;
    }
}

int CreatureVector::getCntBySpeciesID(int ID)
{
    if (ID == Parameters::paraCow::speciesID)
    {
        return cntCow;
    }
    else if (ID == Parameters::paraSheep::speciesID)
    {
        return cntSheep;
    }
    else if (ID == Parameters::paraWolf::speciesID)
    {
        return cntWolf;
    }
    else if (ID == Parameters::paraTiger::speciesID)
    {
        return cntTiger;
    }

    return 0;
}

void CreatureVector::clearCnt()
{
    cntTiger = 0;
    cntWolf = 0;
    cntSheep = 0;
    cntCow = 0;
}

int CreatureVector::getMin(int a, int b)
{
	if (a > b) return b;
	else return a;
}


