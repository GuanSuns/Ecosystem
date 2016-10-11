#include "Creature.h"


Creature::Creature()
{
	speciesID = 0;
	this->thirst = 0;
	this->health = 1;
	this->pGlobalState = nullptr;
	isUpdated = false;
	isDead = false;
}

Creature::Creature(int speciesID, int LocationX, int LocationY, BasicState* pGlobalState)
{
	this->speciesID = speciesID;
	this->pGlobalState = pGlobalState;
	this->health = Parameters::getMaxHealth(speciesID);
	this->thirst = 0; 
	(this->location).x = LocationX;
	(this->location).y = LocationY;
	isUpdated = false;
	isDead = false;
}


Creature::~Creature()
{
}

void Creature::modifyHealth(int val)
{
	this->health = this->health + val;
	if (this->health > Parameters::getMaxHealth(this->getSpeciesID())) this->health = Parameters::getMaxHealth(this->getSpeciesID());
	return;
}

void Creature::modifyThirst(int val)
{
	this->thirst = this->thirst + val;
	if (this->thirst < 0) this->thirst = 0;
	return;
}
