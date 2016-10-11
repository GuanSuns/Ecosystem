#ifndef INITIALWATER_H
#define INITIALWATER_H

#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "Ecosystem/MapItem.h"
#include "Ecosystem/CreatureVector.h"
#include "Ecosystem/BasicPlant.h"

class initialWater
{
public:
    initialWater();

public:
    static void initial();

private:
    static double f1(int y);
    static double f2(int y);
    static double f3(int y);
    static double f4(int y);
    static double f5(int x);
    static double f6(int x);
    static double f7(int x);
    static double f8(int x);
    static double f9(int x);
    static int generateRand(int maxRange);
    static void diamondSquare(int sign, int maxRange, double line[], int str, int ter, float changeRate);

};

#endif // INITIALWATER_H
