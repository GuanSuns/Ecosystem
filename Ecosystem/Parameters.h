#ifndef PARAMETERS_H
#define PARAMETERS_H

class Parameters
{
public:
	Parameters();
	~Parameters();

public:

	static int getPreyCost(int);
	static int getPreyAbility(int);
	static int getNutrition(int);
	static int getMaxHealth(int);
	static int getMaxThirst(int);
	static int getDeath(int);
	static int getEyesight(int);
	static int getSpeed(int);
	static double getBirthrate(int);
	static double getMountainCoefficient(int);
	static double getWaterCoefficient(int);
	static double getForestCoefficient(int);
	static int getLifeExpenseWater(int);
	static int getLifeExpenseHealth(int);
	static double getVigour(int);
	static double getHungerCoefficient();
	static double getHungerFeelingCoefficient();
	static int getACoefficient();
	static bool isFood(int, int);
	static bool isDanger(int, int);
    static int getMinBirthAge(int);
    static int getMaxBirthAge(int);


public:

	static const double hungerCoefficient;
	static const double hungerFeelingCoefficient;
	static const int ACoefficient;
	static const int ChangeDirectionFrequence;
    static const int maxPlant;


	static struct paraGrass			//�ݵĲ���
	{
		static const int speciesID;  //�����ߵ�ID
		static const double birthrate; //��Ⱥ������
		static const int nutrition;		//����ʳ��õ�Ӫ��
	}paraGrass;

	static struct paraWater
	{
		static const int speciesID;
		static const double birthrate; //��Ⱥ������
		static const int nutrition;		//����ʳ��õ�Ӫ��
	}paraWater;


	static struct paraCow                      //ţ�Ĳ���
	{
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //����ID
		static const int preyedCost;	//��ʳ�Ѷ�
		static const int nutrition;		//����ʳ��õ�Ӫ��
		static const int maxHealth;		//�������ֵ��������ÿ���ƶ�������������ֵ���Զ�����������ֵ��
		static const int maxThirst;      //��������ܵĿڿʳ̶�
		static const double birthrate;	//��Ⱥ������
		static const int death;			//��������
		static const int eyesight;		 //�ڵ�ͼ����������Ұ��Χ�����ڷ��ֵ����Լ�ʳ��
		static const int speed;			// ƽ���˶��ٶ�
		static const double mountainCoefficient;  //ɽ���ٶ�Ӱ����������0.8, 0.3��
		static const double waterCoefficient;  //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��
		static const double forestCoefficient;   // �����ٶ�Ӱ�����أ���0.3�� 0.6��
		static const int lifeExpense_Health;    //���濪����������
		static const int lifeExpense_Thirst;	//���濪����ˮ������
		static const double vigour;            //�������Ա������Ƿ��˶�(����0��С��1)
	}paraCow;


	static struct paraSheep					//����Ĳ���
	{
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //����ID
		static const int preyedCost;	//��ʳ�Ѷ�
		static const int nutrition;		//����ʳ��õ�Ӫ��
		static const int maxHealth;		//����ֵ
		static const int maxThirst;      //��������ܵĿڿʳ̶�
		static const double birthrate;	//��Ⱥ������
		static const int death;			//��������
		static const int eyesight;		 //�ڵ�ͼ����������Ұ��Χ�����ڷ��ֵ����Լ�ʳ��
		static const int speed;			// ƽ���˶��ٶ�
		static const double mountainCoefficient;  //ɽ���ٶ�Ӱ����������0.8, 0.3��
		static const double waterCoefficient;  //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��
		static const double forestCoefficient;   // �����ٶ�Ӱ�����أ���0.3�� 0.6��
		static const int lifeExpense_Health;    //���濪����������
		static const int lifeExpense_Thirst;	//���濪����ˮ������
		static const double vigour;            //�������Ա������Ƿ��˶�(����0��С��1)
	}paraSheep;


	static struct paraTiger				//�ϻ��Ĳ���
	{
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //����ID
		static const int preyAbility;	//��ʳ����
		static const int maxHealth;		//����ֵ
		static const int maxThirst;      //��������ܵĿڿʳ̶�
		static const double birthrate;	//��Ⱥ������
		static const int death;			//��������
		static const int eyesight;		 //�ڵ�ͼ����������Ұ��Χ�����ڷ��ֵ����Լ�ʳ��
		static const int speed;			// ƽ���˶��ٶ�
		static const double mountainCoefficient;  //ɽ���ٶ�Ӱ����������0.8, 0.3��
		static const double waterCoefficient;  //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��
		static const double forestCoefficient;   // �����ٶ�Ӱ�����أ���0.3�� 0.6��
		static const int lifeExpense_Health;    //���濪����������
		static const int lifeExpense_Thirst;	//���濪����ˮ������
		static const double vigour;            //�������Ա������Ƿ��˶�(����0��С��1)
	}paraTiger;


	static struct paraWolf				//�ǵĲ���
    {
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //����ID
		static const int preyAbility;	//��ʳ����
		static const int maxHealth;		//����ֵ
		static const int maxThirst;      //��������ܵĿڿʳ̶�
		static const double birthrate;	//��Ⱥ������
		static const int death;			//��������
		static const int eyesight;		 //�ڵ�ͼ����������Ұ��Χ�����ڷ��ֵ����Լ�ʳ��
		static const int speed;			// ƽ���˶��ٶ�
		static const double mountainCoefficient;  //ɽ���ٶ�Ӱ����������0.8, 0.3��
		static const double waterCoefficient;  //ˮ�ٶ�Ӱ�����أ�½������Ϊ0��
		static const double forestCoefficient;   // �����ٶ�Ӱ�����أ���0.3�� 0.6��
		static const int lifeExpense_Health;    //���濪����������
		static const int lifeExpense_Thirst;	//���濪����ˮ������
		static const double vigour;            //�������Ա������Ƿ��˶�(����0��С��1)
	}paraWolf;


};


#endif
