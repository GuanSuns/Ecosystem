#include "InfoDispatchMachine.h"

InfoDispatchMachine infoDispatchMachine;

InfoDispatchMachine::InfoDispatchMachine()
{
}


InfoDispatchMachine::~InfoDispatchMachine()
{
	infoList.clear();
}

void InfoDispatchMachine::UpLoadInfo(Info* info)
{
	if (!isInMachine(info))
	{
		std::cout << "Get Upload" << std::endl;

		infoList.push_back(info);
	}
	else
	{
		delete info;
	}
	return;
}

void InfoDispatchMachine::getInfo(std::vector<Info*>& receiver, Creature* group, int type)
{
	if (infoList.size() == 0) return;

	std::list<Info*>::iterator it = infoList.begin();
	for (; it != infoList.end(); it++)
	{
		if ((*it)->infoType == type
			&& (*it)->sender == group
			)
		{
			receiver.push_back(*it);
		}
	}
	return;
}

bool InfoDispatchMachine::clearInfo()
{
	if (infoList.size() == 0) return false;

	std::list<Info*>::iterator it = infoList.begin();
	for (; it != infoList.end(); it++)
	{
		delete	(*it);
	}

	infoList.clear();
	return true;
}

bool InfoDispatchMachine::isInMachine(Info* info)
{
	if (infoList.size() == 0) return false;

	std::list<Info*>::iterator it = infoList.begin();
	for (; it != infoList.end(); it++)
	{
		if ((*it)->infoType == info->infoType
			&& (*it)->observed == info->observed
			&& (*it)->sender == info->sender
			)
			return true;
	}
	return false;
}

const int InfoDispatchMachine::infoType_Danger=1;

const int InfoDispatchMachine::infoType_Food=2;

const int InfoDispatchMachine::infoType_Water=3;


