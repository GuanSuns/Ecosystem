#include "MemorySystem.h"


MemorySystem::MemorySystem()
{
	cntMemory = 0;
}


MemorySystem::~MemorySystem()
{
}

void MemorySystem::getMemory(std::vector<MemoryItem>& receiver, int Type)
{
	if (memoryList.empty()) return;
	MemoryItem tempMemory;

	std::list<MemoryItem>::iterator it = memoryList.begin();

	for (; it != memoryList.end(); it++)
	{
		if ((*it).memoryType == Type)
		{
			tempMemory.memoryDestination = (*it).memoryDestination;
			tempMemory.memoryType = (*it).memoryType;
			receiver.push_back(tempMemory);
		}
	}

	return;
}

void MemorySystem::UpLoadMemory(MemoryItem newItem)
{

	if (isInMemory(newItem) == true) return;

	std::cout << "Memory Get Uploaded" << std::endl;

	if (cntMemory == maxMemory)
	{
		memoryList.pop_front();
		memoryList.push_back(newItem);
		return;
	}
	else
	{
		memoryList.push_back(newItem);
		cntMemory++;
		return;
	}
	return;
}

bool MemorySystem::isInMemory(MemoryItem& newItem)
{
	if (memoryList.empty()) return false;

	//std::cout << "Test Memory\n";

	std::list<MemoryItem>::iterator it = memoryList.begin();

	for (; it != memoryList.end(); it++)
	{
		if ((*it).memoryDestination == newItem.memoryDestination
			&& (*it).memoryType == newItem.memoryType
			)
		{
			return true;
		}
	}

	return false;
}

void MemorySystem::copyMemory(MemorySystem& fatherMemory)
{
	if (fatherMemory.memoryList.empty()) return;

	std::list<MemoryItem>::iterator it = fatherMemory.memoryList.begin();
	memoryList.clear();
	MemoryItem tempMemory;

	for (; it != fatherMemory.memoryList.end(); it++)
	{
		tempMemory.memoryDestination = (*it).memoryDestination;
		tempMemory.memoryType = (*it).memoryType;
		memoryList.push_back(tempMemory);
	}

	return;
}

const int MemorySystem::memoryType_Water = 1;
const int MemorySystem::memoryType_Food = 2;
const int MemorySystem::maxMemory = 15;
