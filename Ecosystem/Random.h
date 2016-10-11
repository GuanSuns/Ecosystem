#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include <time.h>
#include <iostream>

class Random
{
public:
	Random();
	Random(unsigned int);
	~Random();

public:
	double getRandom(double, double);

private:
	unsigned int seed;
};

extern Random random;

#endif

