#include "initialanimal.h"

initialAnimal::initialAnimal()
{

}

void initialAnimal::initial()
{
    initialTiger();
    initialCow();
    initialSheep();
    initialWolf();

}

void initialAnimal::initialCow()
{
    Herbivore* cow = new Herbivore(Parameters::paraCow::speciesID, 40, 80, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow);

    cow = new Herbivore(Parameters::paraCow::speciesID, 5, 80, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow,15);

    cow = new Herbivore(Parameters::paraCow::speciesID, 70, 360, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow,15);

    cow = new Herbivore(Parameters::paraCow::speciesID, 185, 350, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow,15);

    cow = new Herbivore(Parameters::paraCow::speciesID, 124, 285, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow,15);

    cow = new Herbivore(Parameters::paraCow::speciesID, 136, 56, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow,15);

    cow = new Herbivore(Parameters::paraCow::speciesID, 16, 320, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow,10);

    cow = new Herbivore(Parameters::paraCow::speciesID, 130, 220, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(cow,10);

}

void initialAnimal::initialTiger()
{
    Carnivore* tiger = new Carnivore(Parameters::paraTiger::speciesID, 100, 30, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(tiger,10);

    tiger = new Carnivore(Parameters::paraTiger::speciesID, 30, 130, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(tiger,10);

    tiger = new Carnivore(Parameters::paraTiger::speciesID, 165, 213, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(tiger,10);

    tiger = new Carnivore(Parameters::paraTiger::speciesID, 150, 350, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(tiger,10);
}

void initialAnimal::initialWolf()
{
    Carnivore *wolf = new Carnivore(Parameters::paraWolf::speciesID, 90, 330, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(wolf,5);

    wolf = new Carnivore(Parameters::paraWolf::speciesID, 130, 220, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(wolf,10);

    wolf = new Carnivore(Parameters::paraWolf::speciesID, 90, 210, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(wolf,10);

    wolf = new Carnivore(Parameters::paraWolf::speciesID, 22, 257, Carnivore_GlobalStates::getInstance());
    mCreatureVector.Add(wolf,15);
}

void initialAnimal::initialSheep()
{
    Herbivore* sheep = new Herbivore(Parameters::paraSheep::speciesID, 105, 70, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(sheep,15);

    sheep = new Herbivore(Parameters::paraSheep::speciesID, 176, 33, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(sheep,15);

    sheep = new Herbivore(Parameters::paraSheep::speciesID, 78, 259, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(sheep,10);

    sheep = new Herbivore(Parameters::paraSheep::speciesID, 107, 165, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(sheep,10);

    sheep = new Herbivore(Parameters::paraSheep::speciesID, 186, 186, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(sheep,15);

    sheep = new Herbivore(Parameters::paraSheep::speciesID, 115, 385, Herbivore_GlobalStates::getInstance());
    mCreatureVector.Add(sheep,15);
}

