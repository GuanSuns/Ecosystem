#include "initialwater.h"



initialWater::initialWater()
{

}

void initialWater::initial()
{
    srand((unsigned int)time(NULL));
    double line1[20];
    double line2[20];
    int sign1,sign2;
    int x1,x2,y,x,tempCnt;

    //Çàº£ºþ
    BasicPlant *water = new BasicPlant(Parameters::paraWater::speciesID, 50, 50, nullptr);
    mCreatureVector.Add(water);
    tempCnt = 0;
    for(y=24;y<=75;y++)
    {
        const float H=0.5;
        const float changeRate = powf(2.0,-H);

        if(tempCnt == 0)
        {
            line1[0]=0;
            line1[19]=0;
            line2[0]=0;
            line2[19]=0;

            sign1 = generateRand(2);
            if(sign1==0) sign1=-1;
            sign2 = generateRand(2);
            if(sign2==0) sign2=-1;

            diamondSquare(sign1, 8, line1,0,19,changeRate);
            diamondSquare(sign2, 8, line2,0,19,changeRate);
        }

        x1 = (int)(f1(y) + line1[tempCnt]);
        x2= (int)(f2(y) + line2[tempCnt]);
        for( int i=x1 ; i<=x2 ; i++)
        {
            if(Map[i][y].plant == nullptr)
            {
                Map[i][y].plant = water;
            }
        }

        tempCnt = (tempCnt+1)%20;
    }

    //¶´Í¥ºþ
    water = new BasicPlant(Parameters::paraWater::speciesID, 64, 207, nullptr);
    mCreatureVector.Add(water);
    tempCnt = 0;
    for(y=176;y<=227;y++)
    {
        const float H=0.5;
        const float changeRate = powf(2.0,-H);

        if(tempCnt == 0)
        {
            line1[0]=0;
            line1[19]=0;
            line2[0]=0;
            line2[19]=0;

            sign1 = generateRand(2);
            if(sign1==0) sign1=-1;
            sign2 = generateRand(2);
            if(sign2==0) sign2=-1;

            diamondSquare(sign1, 8, line1,0,19,changeRate);
            diamondSquare(sign2, 8, line2,0,19,changeRate);
        }

        x1 = (int)(f3(y) + line1[tempCnt]);
        x2= (int)(f4(y) + line2[tempCnt]);
        for( int i=x1 ; i<=x2 ; i++)
        {
            if(Map[i][y].plant == nullptr)
            {
                Map[i][y].plant = water;
            }
        }

        tempCnt = (tempCnt+1)%20;
    }

    //ãò¹Áºþ
    water = new BasicPlant(Parameters::paraWater::speciesID, 158, 121, nullptr);
    mCreatureVector.Add(water);
    tempCnt = 0;
    for(x=129;x<=183;x++)
    {
        const float H=0.5;
        const float changeRate = powf(2.0,-H);

        if(tempCnt == 0)
        {
            line1[0]=0;
            line1[19]=0;
            line2[0]=0;
            line2[19]=0;

            sign1 = generateRand(2);
            if(sign1==0) sign1=-1;
            sign2 = generateRand(2);
            if(sign2==0) sign2=-1;

            diamondSquare(sign1, 8, line1,0,19,changeRate);
            diamondSquare(sign2, 8, line2,0,19,changeRate);
        }

        x1 = (int)(f5(x) + line1[tempCnt]);
        x2= (int)(f6(x) + line2[tempCnt]);
        for( int i=x1 ; i<=x2 ; i++)
        {
            if(Map[x][i].plant == nullptr)
            {
                Map[x][i].plant = water;
            }
        }

        tempCnt = (tempCnt+1)%20;
    }


    //Û¶Ñôºþ
    water = new BasicPlant(Parameters::paraWater::speciesID, 109, 317, nullptr);
    mCreatureVector.Add(water);
    tempCnt = 0;
    for(x=61;x<=130;x++)
    {
        const float H=0.5;
        const float changeRate = powf(2.0,-H);

        if(tempCnt == 0)
        {
            line1[0]=0;
            line1[19]=0;
            line2[0]=0;
            line2[19]=0;

            sign1 = generateRand(2);
            if(sign1==0) sign1=-1;
            sign2 = generateRand(2);
            if(sign2==0) sign2=-1;

            diamondSquare(sign1, 1, line1,0,19,changeRate);
            diamondSquare(sign2, 1, line2,0,19,changeRate);
        }

        x1 = (int)(f7(x) + line1[tempCnt]);
        x2= (int)(f8(x) + line2[tempCnt]);
        for( int i=x1 ; i<=x2 ; i++)
        {
            if(Map[x][i].plant == nullptr)
            {
                Map[x][i].plant = water;
            }
        }

        tempCnt = (tempCnt+1)%20;
    }

    water = new BasicPlant(Parameters::paraWater::speciesID, 141, 319, nullptr);
    mCreatureVector.Add(water);
    tempCnt = 0;
    for(x=131;x<=160;x++)
    {
        const float H=0.5;
        const float changeRate = powf(2.0,-H);

        if(tempCnt == 0)
        {
            line1[0]=0;
            line1[19]=0;
            line2[0]=0;
            line2[19]=0;

            sign1 = generateRand(2);
            if(sign1==0) sign1=-1;
            sign2 = generateRand(2);
            if(sign2==0) sign2=-1;

            diamondSquare(sign1, 1, line1,0,19,changeRate);
            diamondSquare(sign2, 1, line2,0,19,changeRate);
        }

        x1 = (int)(f7(x) + line1[tempCnt]);
        x2= (int)(f9(x) + line2[tempCnt]);
        for( int i=x1 ; i<=x2 ; i++)
        {
            if(Map[x][i].plant == nullptr)
            {
                Map[x][i].plant = water;
            }
        }

        tempCnt = (tempCnt+1)%20;
    }



}

double initialWater::f1(int y)
{
    return (-1.0)*y*y*0.0000018483*y*y*y + y*0.0004088754*y*y*y - y*0.0344176603*y*y + 1.4135092457*y*y - 29.6977593390*y + 297.32665535;
}

double initialWater::f2(int y)
{
    return (-1.0)*y*y*0.0000047432*y*y*y + y*0.0010935778*y*y*y - y*0.0965903651*y*y + 4.0425414419*y*y - 78.6095929178*y + 611.5344892689 ;
}

double initialWater::f3(int y)
{
    return (1.0)*y*y*0.0000047250*y*y*y - y*0.0047208742*y*y*y + y*1.88170542*y*y - 374.0473434*y*y + 37082.596941894*y - 1466822.98330;
}

double initialWater::f4(int y)
{
    return (-1.0)*y*y*0.0000006543*y*y*y + y*0.0006213995*y*y*y - y*0.2357154298*y*y + 44.6156857671*y*y - 4210.82134*y + 158469.1253471 ;
}

double initialWater::f5(int x)
{
    return (1.0)*x*0.0000115213*x*x*x - x*0.0075244561*x*x + 1.8406949403*x*x - 199.6652003443*x + 8207.9687450;
}

double initialWater::f6(int x)
{
    return (1.0)*x*x*0.0000081478*x*x*x - x*x*0.0064681230*x*x + x*2.0445968006*x*x - x*321.6866307350*x + 25191.701246001*x - 785429.2358981450 ;
}

double initialWater::f7(int x)
{
    return (1.0)*x*x*0.0000001040*x*x*x - x*x*0.0000538575*x*x + x*0.0107981785*x*x - x*1.0429127084*x + 48.1925661853*x - 534.1809635757 ;
}

double initialWater::f8(int x)
{
    return (-1.0)*x*x*0.0000006183*x*x*x + x*x*0.0002543058*x*x - x*0.0403198610*x*x + x*3.0741522632*x - 112.3448006984*x + 1885.0006176769  ;
}

double initialWater::f9(int x)
{
    return (-1.0)*x*x*0.0008926909*x*x + x*0.5134100099*x*x - x*110.5325591298*x + 10557.602981*x - 377161.44428441  ;
}

void initialWater::diamondSquare(int sign, int maxRange, double line[], int str, int ter, float changeRate)
{
    static const int minDistance = 6;
    double d = 0;

    if(ter-str < minDistance || str >= ter) return;
    if(maxRange==0) maxRange=1;

    int mid = (str+ter)/2;
    int tempRand = generateRand(maxRange);
    line[mid] = (double)(tempRand*sign);

    d=(line[mid]-line[str])/(mid-str+1);
    for(int i=str;i<mid-1;i++)
    {
        line[i+1]=line[i]+d;
    }

    d=(line[ter]-line[mid])/(ter-mid+1);
    for(int i=mid;i<ter-1;i++)
    {
        line[i+1]=line[i]+d;
    }

    diamondSquare(sign,(int)(maxRange*changeRate),line,str,mid,changeRate);
    diamondSquare(sign, (int)(maxRange*changeRate),line,mid,ter,changeRate);

    return;
}

int initialWater::generateRand(int maxRange)
{
    if(maxRange<=0) return 0;

    int r = rand() % maxRange;
    return r;
}

