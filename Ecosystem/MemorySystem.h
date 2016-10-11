#ifndef MEMORY_SYSTEM_H
#define MEMORY_SYSTEM_H

#include "Location.h"
#include "Creature.h"
#include <list>
#include <vector>
#include <iostream>



struct MemoryItem
{
	Creature* memoryDestination;
	int memoryType;
};

class MemorySystem
{
public:
	MemorySystem();
	~MemorySystem();

public:

	void UpLoadMemory(MemoryItem);
	void getMemory(std::vector<MemoryItem>&, int);
	void copyMemory(MemorySystem&);

public:
	std::list<MemoryItem> memoryList;
	int cntMemory;
	bool isInMemory(MemoryItem&);

public:
	static const int memoryType_Water;
	static const int memoryType_Food;
	static const int maxMemory;

};


#endif

