#include "ecosystemscene.h"
#include "scrollqgraphicsview.h"

#include <iostream>

EcosystemScene::EcosystemScene()
    :QGraphicsScene(0, 0, 300, 300)
{

}

EcosystemScene::EcosystemScene(qreal width, qreal height)
    :QGraphicsScene(0, 0, width, height)
{
    unitWidth = width/(qreal)MapParameters::maxMapWidth;
    unitHeight=height/(qreal)MapParameters::maxMapHeight;

    viewColor.setRed(228);
    viewColor.setGreen(162);
    viewColor.setBlue(84);


    //std::cout<<"UnitWidth "<<unitWidth<<std::endl;

    //pixBackground.load(":/sourceImages/Images/Land.png");

    //this->setBackgroundBrush(pixBackground);

    this->setBackgroundBrush(viewColor);
    this->setSceneRect(0,0,width,height);
    reDraw();
}

void EcosystemScene::reDraw()
{
    this->clear();

    /*
    if(viewParameters::factor > viewParameters::threshold )
    {
        this->setBackgroundBrush(pixBackground);
    }
    else
    {
        this->setBackgroundBrush(viewColor);
    }
    */

    this->setBackgroundBrush(viewColor);

    /*
    int i=  MapParameters::maxMapHeight-1;
    int j=  MapParameters::maxMapWidth-1;

    CreatureItem *item = new CreatureItem( unitWidth, unitHeight, Parameters::paraCow::speciesID);
    item->setPos(QPointF(j*unitWidth, i*unitHeight));
    this->addItem(item);

    item = new CreatureItem( unitWidth, unitHeight, Parameters::paraCow::speciesID);
    item->setPos(QPointF(0, 0));

    this->addItem(item);
    */

    for(int i=0; i < MapParameters::maxMapHeight ; i++)
    {
        for(int j=0; j < MapParameters::maxMapWidth ; j++)
        {
            if( Map[i][j].animal != nullptr )
            {
                CreatureItem *item = new CreatureItem( unitWidth, unitHeight, Map[i][j].animal->getSpeciesID());
                item->setPos(QPointF(j*unitWidth, i*unitHeight));
                this->addItem(item);
            }
            else if( Map[i][j].plant != nullptr )
            {
                CreatureItem *item = new CreatureItem( unitWidth, unitHeight, Map[i][j].plant->getSpeciesID());
                item->setPos(QPointF(j*unitWidth, i*unitHeight));
                this->addItem(item);
            }
        }
    }

}

