#ifndef CREATURE_H
#define CREATURE_H

#include "Location.h"
#include "Parameters.h"
#include "BasicState.h"

class Creature
{
public:
	Creature();
	Creature(int, int, int, BasicState*);
	~Creature();

public:
	virtual void Update() = 0;
	virtual void Die() = 0;
	virtual void Born(int) = 0;

	bool IsDead() { return isDead; }
	int getSpeciesID() const { return speciesID; }
	int getThirst() const { return thirst; }
	int getHealth() const { return health; }

	void modifyThirst(int);
	void modifyHealth(int);
	Creature* getGroup() const { return group; }
	void setGroup(Creature* val) { group = val; }
	virtual bool add(Creature*) =0;

public:
	Location location;
	bool isUpdated;

protected:
	BasicState* pGlobalState;
	Creature* group;

	bool isDead;						//�Ƿ�������
	int speciesID;
	int health;				//��ǰ����״��
	int thirst;				//��ǰ���ʳ̶�
};

#endif