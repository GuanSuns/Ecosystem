#include "Random.h"


Random::Random()
{
	//std::cout << "None parameters random\n";
}

Random::Random(unsigned int seed)
{
	//std::cout << "With Parameters random\n";
	this->seed = seed;
	srand(this->seed);
}

Random::~Random()
{
}

double Random::getRandom(double sta, double ter)
{
	int r = rand() % 101;
	double number = (double)r / 100.0;
	return sta + number*(ter - sta);
}

Random random(time(NULL));