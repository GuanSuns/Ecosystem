#include "MapItem.h"


MapItem::MapItem()
{
	
}


MapItem::~MapItem()
{
}

void MapParameters::Mod(Location& location)
{
	if (location.x < 0)  location.x = MapParameters::maxMapHeight + location.x;
	else location.x = location.x % MapParameters::maxMapHeight;
	if (location.y < 0)  location.y = MapParameters::maxMapWidth + location.y;
	else location.y = location.y % MapParameters::maxMapWidth;

	return;
}

MapItem Map[MapParameters::maxMapHeight][MapParameters::maxMapWidth];
int mapFlag[MapParameters::maxMapHeight][MapParameters::maxMapWidth];


void MapParameters::InitialMap()
{
	for (int i = 0; i < MapParameters::maxMapHeight; i++)
	{
		for (int j = 0; j < MapParameters::maxMapWidth; j++)
		{
			Map[i][j].animal = nullptr;
			Map[i][j].plant = nullptr;
		}
	}
}


