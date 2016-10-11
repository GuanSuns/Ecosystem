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


	static struct paraGrass			//草的参数
	{
		static const int speciesID;  //生产者的ID
		static const double birthrate; //种群出生率
		static const int nutrition;		//被捕食获得的营养
	}paraGrass;

	static struct paraWater
	{
		static const int speciesID;
		static const double birthrate; //种群出生率
		static const int nutrition;		//被捕食获得的营养
	}paraWater;


	static struct paraCow                      //牛的参数
	{
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //物种ID
		static const int preyedCost;	//捕食难度
		static const int nutrition;		//被捕食获得的营养
		static const int maxHealth;		//最高生命值（体力，每次移动都会消耗生命值，吃东西补充生命值）
		static const int maxThirst;      //最高能忍受的口渴程度
		static const double birthrate;	//种群出生率
		static const int death;			//死亡代数
		static const int eyesight;		 //在地图中搜索的视野范围，用于发现敌人以及食物
		static const int speed;			// 平地运动速度
		static const double mountainCoefficient;  //山地速度影响因数（如0.8, 0.3）
		static const double waterCoefficient;  //水速度影响因素（陆生动物为0）
		static const double forestCoefficient;   // 树林速度影响因素（如0.3， 0.6）
		static const int lifeExpense_Health;    //生存开销，饥饿度
		static const int lifeExpense_Thirst;	//生存开销，水的消耗
		static const double vigour;            //活力，吃饱喝足是否运动(大于0，小于1)
	}paraCow;


	static struct paraSheep					//绵羊的参数
	{
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //物种ID
		static const int preyedCost;	//捕食难度
		static const int nutrition;		//被捕食获得的营养
		static const int maxHealth;		//生命值
		static const int maxThirst;      //最高能忍受的口渴程度
		static const double birthrate;	//种群出生率
		static const int death;			//死亡代数
		static const int eyesight;		 //在地图中搜索的视野范围，用于发现敌人以及食物
		static const int speed;			// 平地运动速度
		static const double mountainCoefficient;  //山地速度影响因数（如0.8, 0.3）
		static const double waterCoefficient;  //水速度影响因素（陆生动物为0）
		static const double forestCoefficient;   // 树林速度影响因素（如0.3， 0.6）
		static const int lifeExpense_Health;    //生存开销，饥饿度
		static const int lifeExpense_Thirst;	//生存开销，水的消耗
		static const double vigour;            //活力，吃饱喝足是否运动(大于0，小于1)
	}paraSheep;


	static struct paraTiger				//老虎的参数
	{
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //物种ID
		static const int preyAbility;	//捕食能力
		static const int maxHealth;		//生命值
		static const int maxThirst;      //最高能忍受的口渴程度
		static const double birthrate;	//种群出生率
		static const int death;			//死亡代数
		static const int eyesight;		 //在地图中搜索的视野范围，用于发现敌人以及食物
		static const int speed;			// 平地运动速度
		static const double mountainCoefficient;  //山地速度影响因数（如0.8, 0.3）
		static const double waterCoefficient;  //水速度影响因素（陆生动物为0）
		static const double forestCoefficient;   // 树林速度影响因素（如0.3， 0.6）
		static const int lifeExpense_Health;    //生存开销，饥饿度
		static const int lifeExpense_Thirst;	//生存开销，水的消耗
		static const double vigour;            //活力，吃饱喝足是否运动(大于0，小于1)
	}paraTiger;


	static struct paraWolf				//狼的参数
    {
        static const int maxBirthAge;
        static const int minBirthAge;
		static const int speciesID;	    //物种ID
		static const int preyAbility;	//捕食能力
		static const int maxHealth;		//生命值
		static const int maxThirst;      //最高能忍受的口渴程度
		static const double birthrate;	//种群出生率
		static const int death;			//死亡代数
		static const int eyesight;		 //在地图中搜索的视野范围，用于发现敌人以及食物
		static const int speed;			// 平地运动速度
		static const double mountainCoefficient;  //山地速度影响因数（如0.8, 0.3）
		static const double waterCoefficient;  //水速度影响因素（陆生动物为0）
		static const double forestCoefficient;   // 树林速度影响因素（如0.3， 0.6）
		static const int lifeExpense_Health;    //生存开销，饥饿度
		static const int lifeExpense_Thirst;	//生存开销，水的消耗
		static const double vigour;            //活力，吃饱喝足是否运动(大于0，小于1)
	}paraWolf;


};


#endif
