#ifndef INITIALANIMAL_H
#define INITIALANIMAL_H

#include "Ecosystem/MapItem.h"
#include "Ecosystem/CreatureVector.h"
#include "Ecosystem/Carnivore.h"
#include "Ecosystem/Herbivore.h"
#include "Ecosystem/Parameters.h"

class initialAnimal
{
public:
    initialAnimal();

public:
    static void initial();

private:
    static void initialCow();
    static void initialTiger();
    static void initialWolf();
    static void initialSheep();
};

#endif // INITIALANIMAL_H
