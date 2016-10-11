#include "Parameters.h"


Parameters::Parameters()
{
}


Parameters::~Parameters()
{
}

const double Parameters::hungerCoefficient = 0.5;
const double Parameters::hungerFeelingCoefficient = 0.6;
const int Parameters::ACoefficient = 10;  //������ڵ���10
const int Parameters::ChangeDirectionFrequence = 10;
const int Parameters::maxPlant = 200;

//�ݵĲ���
const int Parameters::paraGrass::speciesID = 1001;			//�����ߵ�IDȫ������1000
const double Parameters::paraGrass::birthrate = 0.004;		//��Ⱥ������
const int Parameters::paraGrass::nutrition = 90;		//����ʳ��õ�Ӫ��

//ˮ�Ĳ���
const int Parameters::paraWater::speciesID = 1002;			//�����ߵ�IDȫ������1000
const double Parameters::paraWater::birthrate = 0;		//��Ⱥ������
const int Parameters::paraWater::nutrition = 100;		//����ʳ��õ�Ӫ��


//ţ�Ĳ���
const int Parameters::paraCow::maxHealth = 120;		//����ֵ	
const int Parameters::paraCow::maxThirst = 80;		//��������ܵĿڿʳ̶�
const int Parameters::paraCow::nutrition = 80;		//����ʳ��õ�Ӫ���������������ֵΪ���ޣ�
const int Parameters::paraCow::preyedCost = 110;		//��ʳ�Ѷȣ����100���� ��ʳ����������100����ʳ�ѶȽԴ���100
const int Parameters::paraCow::speciesID = 1;		//����ID��ʳ�ݶ���IDȫ��С��100
const double Parameters::paraCow::birthrate = 0.4;	//��Ⱥ������
const int Parameters::paraCow::death = 800;         //��������
const int Parameters::paraCow::eyesight = 18;       //��Ұ
const int Parameters::paraCow::speed = 2;			//ƽ���˶��ٶ�
const int Parameters::paraCow::lifeExpense_Health = 2;
const int Parameters::paraCow::lifeExpense_Thirst = 2;
const double Parameters::paraCow::vigour = 0.3;            //�������Ա������Ƿ��˶�(����0��С��1),���ڴ˲������˶����������˶�
const int Parameters::paraCow::maxBirthAge = 30;
const int Parameters::paraCow::minBirthAge = 25;
const double Parameters::paraCow::forestCoefficient = 0.4; // �����ٶ�Ӱ�����أ���0.3�� 0.6��
const double Parameters::paraCow::mountainCoefficient = 0.2; //ɽ���ٶ�Ӱ����������0.8, 0.3��
const double Parameters::paraCow::waterCoefficient = 0;   //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��

//����Ĳ���
const int Parameters::paraSheep::maxHealth = 100;		//����ֵ
const int Parameters::paraSheep::maxThirst = 90;			//��������ܵĿڿʳ̶�
const int Parameters::paraSheep::nutrition = 50;		//����ʳ��õ�Ӫ��
const int Parameters::paraSheep::preyedCost = 100;		//��ʳ�Ѷ�
const int Parameters::paraSheep::speciesID = 2;		//����ID
const double Parameters::paraSheep::birthrate = 0.6;	//��Ⱥ������
const int Parameters::paraSheep::death = 600;         //��������
const int Parameters::paraSheep::eyesight = 20;       //��Ұ
const int Parameters::paraSheep::speed = 3;			//ƽ���˶��ٶ�
const double Parameters::paraSheep::forestCoefficient = 0.7; // �����ٶ�Ӱ�����أ���0.3�� 0.6��
const double Parameters::paraSheep::mountainCoefficient = 0.9; //ɽ���ٶ�Ӱ����������0.8, 0.3��
const double Parameters::paraSheep::waterCoefficient = 0;   //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��
const int Parameters::paraSheep::lifeExpense_Health = 2;
const int Parameters::paraSheep::lifeExpense_Thirst = 1;
const double Parameters::paraSheep::vigour = 0.4;            //�������Ա������Ƿ��˶�(����0��С��1)
const int Parameters::paraSheep::maxBirthAge = 30;
const int Parameters::paraSheep::minBirthAge = 25;

//�ϻ��Ĳ���
const int Parameters::paraTiger::maxHealth = 110;		//����ֵ
const int Parameters::paraTiger::maxThirst = 110;		//��������ܵĿڿʳ̶�
const int Parameters::paraTiger::preyAbility = 100;	//��ʳ����
const int Parameters::paraTiger::speciesID = 101;		//����ID��ʳ�⶯��ȫ������100
const double Parameters::paraTiger::birthrate = 0.7;	//��Ⱥ������
const int Parameters::paraTiger::death = 1000;         //��������
const int Parameters::paraTiger::eyesight = 30;       //��Ұ
const int Parameters::paraTiger::speed = 5;			//ƽ���˶��ٶ�
const double Parameters::paraTiger::forestCoefficient = 0.7; // �����ٶ�Ӱ�����أ���0.3�� 0.6��
const double Parameters::paraTiger::mountainCoefficient = 0.6; //ɽ���ٶ�Ӱ����������0.8, 0.3��
const double Parameters::paraTiger::waterCoefficient = 0;   //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��
const int Parameters::paraTiger::lifeExpense_Health = 2;
const int Parameters::paraTiger::lifeExpense_Thirst = 2;
const double Parameters::paraTiger::vigour = 0.5;            //�������Ա������Ƿ��˶�(����0��С��1)
const int Parameters::paraTiger::maxBirthAge = 30;
const int Parameters::paraTiger::minBirthAge = 25;


//�ǵĲ���
const int Parameters::paraWolf::maxHealth = 110;		//����ֵ	
const int Parameters::paraWolf::maxThirst = 100;		//��������ܵĿڿʳ̶�
const int Parameters::paraWolf::preyAbility = 90;	//��ʳ����
const int Parameters::paraWolf::speciesID = 102;		//����ID
const double Parameters::paraWolf::birthrate = 0.9;	//��Ⱥ������
const int Parameters::paraWolf::death = 800;         //��������
const int Parameters::paraWolf::eyesight = 28;       //��Ұ
const int Parameters::paraWolf::speed = 4;			//ƽ���˶��ٶ�
const double Parameters::paraWolf::forestCoefficient = 0.9; // �����ٶ�Ӱ�����أ���0.3�� 0.6��
const double Parameters::paraWolf::mountainCoefficient = 0.9; //ɽ���ٶ�Ӱ����������0.8, 0.3��
const double Parameters::paraWolf::waterCoefficient = 0;   //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��
const int Parameters::paraWolf::lifeExpense_Health = 2;
const int Parameters::paraWolf::lifeExpense_Thirst = 1;
const double Parameters::paraWolf::vigour = 0.7;            //�������Ա������Ƿ��˶�(����0��С��1)
const int Parameters::paraWolf::maxBirthAge = 30;
const int Parameters::paraWolf::minBirthAge = 25;


//��ؽӿ�
int Parameters::getPreyCost(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::preyedCost;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::preyedCost;
	default:
		return 0;
	}
}

int Parameters::getPreyAbility(int ID)
{
	switch (ID)
	{
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::preyAbility;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::preyAbility;
	default:
		return 0;
	}
}

int Parameters::getNutrition(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::nutrition;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::nutrition;
	case Parameters::paraGrass::speciesID:
		return Parameters::paraGrass::nutrition;
	case Parameters::paraWater::speciesID:
		return Parameters::paraWater::nutrition;
	default:
		return 0;
	}
}

int Parameters::getMaxHealth(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::maxHealth;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::maxHealth;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::maxHealth;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::maxHealth;
	default:
		return 0;
	}
}

int Parameters::getMaxThirst(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::maxThirst;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::maxThirst;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::maxThirst;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::maxThirst;
	default:
		return 0;
	}
}

int Parameters::getSpeed(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::speed;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::speed;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::speed;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::speed;
	default:
		return 0;
	}
}

int Parameters::getEyesight(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::eyesight;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::eyesight;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::eyesight;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::eyesight;
	default:
		return 0;
	}
}

double Parameters::getBirthrate(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::birthrate;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::birthrate;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::birthrate;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::birthrate;
	case Parameters::paraGrass::speciesID:
		return Parameters::paraGrass::birthrate;
	default:
		return 0;
	}
}

double Parameters::getMountainCoefficient(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::mountainCoefficient;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::mountainCoefficient;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::mountainCoefficient;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::mountainCoefficient;
	default:
		return 0;
	}
}

double Parameters::getWaterCoefficient(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::waterCoefficient;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::waterCoefficient;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::waterCoefficient;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::waterCoefficient;
	default:
		return 0;
	}
}

double Parameters::getForestCoefficient(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::forestCoefficient;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::forestCoefficient;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::forestCoefficient;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::forestCoefficient;
	default:
		return 0;
	}
}

int Parameters::getDeath(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::death;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::death;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::death;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::death;
	default:
		return 0;
	}
}

int Parameters::getLifeExpenseWater(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::lifeExpense_Thirst;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::lifeExpense_Thirst;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::lifeExpense_Thirst;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::lifeExpense_Thirst;
	default:
		return 0;
	}
}

int Parameters::getLifeExpenseHealth(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::lifeExpense_Health;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::lifeExpense_Health;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::lifeExpense_Health;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::lifeExpense_Health;
	default:
		return 0;
	}
}

double Parameters::getVigour(int ID)
{
	switch (ID)
	{
	case Parameters::paraCow::speciesID:
		return Parameters::paraCow::vigour;
	case Parameters::paraSheep::speciesID:
		return Parameters::paraSheep::vigour;
	case Parameters::paraTiger::speciesID:
		return Parameters::paraTiger::vigour;
	case Parameters::paraWolf::speciesID:
		return Parameters::paraWolf::vigour;
	default:
		return 0;
	}
}

double Parameters::getHungerCoefficient()
{
	return Parameters::hungerCoefficient;
}

double Parameters::getHungerFeelingCoefficient()
{
	return Parameters::hungerFeelingCoefficient;
}

int Parameters::getACoefficient()
{
	return Parameters::ACoefficient;
}

bool Parameters::isFood(int creatureID, int targetID)
{
	switch (creatureID)
	{
	case Parameters::paraCow::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraGrass::speciesID:
			return true;
		default:
			return false;
		}
	}
	case Parameters::paraSheep::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraGrass::speciesID:
			return true;
		default:
			return false;
		}
	}
	case Parameters::paraTiger::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraCow::speciesID:
			return true;
		case Parameters::paraSheep::speciesID:
			return true;
		default:
			return false;
		}
	}
	case Parameters::paraWolf::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraCow::speciesID:
			return true;
		case Parameters::paraSheep::speciesID:
			return true;
		default:
			return false;
		}
	}
	default:
		return false;
	}
}

bool Parameters::isDanger(int creatureID, int targetID)
{
	switch (creatureID)
	{
	case Parameters::paraCow::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraTiger::speciesID:
			return true;
		case Parameters::paraWolf::speciesID:
			return true;
		default:
			return false;
		}
	}
	case Parameters::paraSheep::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraTiger::speciesID:
			return true;
		case Parameters::paraWolf::speciesID:
			return true;
		default:
			return false;
		}
	}
	case Parameters::paraTiger::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraTiger::speciesID:
			return false;
		default:
			return false;
		}
	}
	case Parameters::paraWolf::speciesID:
	{
		switch (targetID)
		{
		case Parameters::paraWolf::speciesID:
			return false;
		default:
			return false;
		}
	}
	default:
		return false;
    }
}

int Parameters::getMinBirthAge(int ID)
{
    switch (ID)
    {
    case Parameters::paraCow::speciesID:
        return Parameters::paraCow::minBirthAge;
    case Parameters::paraSheep::speciesID:
        return Parameters::paraSheep::minBirthAge;
    case Parameters::paraTiger::speciesID:
        return Parameters::paraTiger::minBirthAge;
    case Parameters::paraWolf::speciesID:
        return Parameters::paraWolf::minBirthAge;
    default:
        return 0;
    }
}

int Parameters::getMaxBirthAge(int ID)
{
    switch (ID)
    {
    case Parameters::paraCow::speciesID:
        return Parameters::paraCow::maxBirthAge;
    case Parameters::paraSheep::speciesID:
        return Parameters::paraSheep::maxBirthAge;
    case Parameters::paraTiger::speciesID:
        return Parameters::paraTiger::maxBirthAge;
    case Parameters::paraWolf::speciesID:
        return Parameters::paraWolf::maxBirthAge;
    default:
        return 0;
    }
}
