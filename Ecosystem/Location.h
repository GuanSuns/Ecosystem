#ifndef LOCATION_H
#define LOCATION_H

struct Location
{
	Location()
	{
		this->x = 0;
		this->y = 0;
	}

	Location(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	~Location()
	{
	}

	int x, y;

};

#endif

