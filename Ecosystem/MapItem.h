#ifndef MAP_ITEM_H
#define MAP_ITEM_H

#include "Creature.h"
#include "Location.h"

struct MapItem
{
	MapItem();
	~MapItem();

	Creature* plant;
	Creature* animal;

};

namespace MapParameters
{
    const int maxMapWidth = 400;
    const int maxMapHeight = 200;
	void Mod(Location&); 
	void InitialMap();
	static const int moveX[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
	static const int moveY[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
}

extern MapItem Map[][MapParameters::maxMapWidth];
extern int mapFlag[MapParameters::maxMapHeight][MapParameters::maxMapWidth];

#endif
