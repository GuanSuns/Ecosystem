#ifndef INFO_DISPATCH_MACHINE_H
#define INFO_DISPATCH_MACHINE_H

#include "Creature.h"
#include <list>
#include <vector>
#include <iostream>


struct Info
{
	int infoType;
	Creature* sender;
	Creature* observed;
};


class InfoDispatchMachine
{
public:
	InfoDispatchMachine();
	~InfoDispatchMachine();

public:
	void UpLoadInfo(Info*);
	void getInfo(std::vector<Info*>&, Creature*, int);
	bool clearInfo();

public:
	static const int infoType_Water;
	static const int infoType_Food;
	static const int infoType_Danger;

private:
	std::list<Info*> infoList;
	bool isInMachine(Info*);
};

extern InfoDispatchMachine infoDispatchMachine;


#endif

