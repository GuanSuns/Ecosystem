#include "initialplant.h"

initialPlant::initialPlant()
{

}

void initialPlant::initial()
{
    BasicPlant *plant = new  BasicPlant(Parameters::paraGrass::speciesID, 126, 20, nullptr);

    if(Map[126][20].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 126, 20, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[131][27].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 131, 27, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[142][19].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 142, 19, nullptr);
        mCreatureVector.Add(plant,5);
    }


    if(Map[165][70].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 165, 70, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[170][77].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 170, 77, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[179][73].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 179, 73, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[157][80].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 157, 80, nullptr);
        mCreatureVector.Add(plant,5);
    }


    if(Map[57][128].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 57, 128, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[75][134].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 75, 134, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[89][132].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 89, 132, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[62][137].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 62, 137, nullptr);
        mCreatureVector.Add(plant,5);
    }

    if(Map[123][186].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 123, 186, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[122][181].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 122, 181, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[131][179].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 131, 179, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[146][177].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 146, 177, nullptr);
        mCreatureVector.Add(plant,5);
    }

    if(Map[93][278].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 93, 278, nullptr);
        mCreatureVector.Add(plant,10);
    }

    if(Map[22][170].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 22, 170, nullptr);
        mCreatureVector.Add(plant,10);
    }

    if(Map[183][367].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 183, 367, nullptr);
        mCreatureVector.Add(plant,10);
    }
    if(Map[176][377].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 176, 377, nullptr);
        mCreatureVector.Add(plant,10);
    }


    if(Map[177][258].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 177, 258, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[184][250].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 184, 250, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[185][260].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 185, 260, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[181][268].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 181, 268, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[181][278].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 181, 278, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[192][247].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 192, 247, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[192][255].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 192, 255, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[192][266].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 192, 266, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[190][273].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 190, 273, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[188][283].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 188, 273, nullptr);
        mCreatureVector.Add(plant,5);
    }


    if(Map[26][354].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 26, 354, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[32][355].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 32, 355, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[36][349].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 36, 349, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[37][360].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 37, 360, nullptr);
        mCreatureVector.Add(plant,5);
    }


    if(Map[31][265].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 31, 265, nullptr);
        mCreatureVector.Add(plant,5);
    }
    if(Map[35][272].plant == nullptr)
    {
        plant = new  BasicPlant(Parameters::paraGrass::speciesID, 35, 272, nullptr);
        mCreatureVector.Add(plant,5);
    }


}

