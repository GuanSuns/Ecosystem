#include "creatureitem.h"
#include "scrollqgraphicsview.h"

#include <iostream>

const int CreatureItem::unitAdd = 3;

CreatureItem::CreatureItem()
{

}

CreatureItem::CreatureItem(qreal mWidth, qreal mHeight, int kind)
{

    mBoundRect.setCoords(-mWidth/2.0,-mHeight/2.0,mWidth/2.0,mHeight/2.0);

    if(kind==Parameters::paraWater::speciesID)
    {
        drawWater(mWidth,mHeight);
    }
    else if(kind==Parameters::paraGrass::speciesID)
    {
        drawGrass(mWidth,mHeight);
    }
    else if(kind==Parameters::paraWolf::speciesID)
    {
        drawWolf(mWidth,mHeight);
    }
    else if(kind==Parameters::paraSheep::speciesID)
    {
        drawSheep(mWidth,mHeight);
    }
    else if(kind==Parameters::paraCow::speciesID)
    {
        drawCow(mWidth,mHeight);
    }
    else if(kind==Parameters::paraTiger::speciesID)
    {
        drawTiger(mWidth,mHeight);
    }
}

QRectF CreatureItem::boundingRect() const
{
    return QRectF( mBoundRect.left(),
                   mBoundRect.top(),
                   mBoundRect.width(),
                   mBoundRect.height()
                   );
}

void CreatureItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * /* widget */)
{
    //std::cout<<"\n\n"<<option->levelOfDetail<<"\n\n";
    /*
    if(viewParameters::factor > viewParameters::threshold )
    {
        //this->setBackgroundBrush(pixBackground);
    }
    else
    {
        painter->fillPath(shape,color);
    }
    */

    painter->fillPath(shape,color);

    return;
}

void CreatureItem::drawWater(qreal mWidth, qreal mHeight)
{
    int R=0;
    int G=162;
    int B=232;
    color.setRgb(R,G,B);

    //mBoundRect.adjust(0,0,unitAdd, unitAdd);
    shape.addRect(boundingRect());
}

void CreatureItem::drawGrass(qreal mWidth, qreal mHeight)
{
    int R=0;
    int G=145;
    int B=0;
    color.setRgb(R,G,B);

    //mBoundRect.adjust(0,0,unitAdd, unitAdd);
    shape.addRect(boundingRect());

    /*
    if(viewParameters::factor > viewParameters::threshold )
    {
        picture.load(":/sourceImages/Images/Grass.png");
        picture = picture.scaled(QSize(mBoundRect.width(),mBoundRect.height()), Qt::IgnoreAspectRatio);
    }
    */

}

void CreatureItem::drawTiger(qreal mWidth, qreal mHeight)
{
    int R=255;
    int G=255;
    int B=0;
    color.setRgb(R,G,B);

    mBoundRect.adjust(0,0,unitAdd, unitAdd);
    shape.addEllipse(boundingRect());

}

void CreatureItem::drawWolf(qreal mWidth, qreal mHeight)
{
    int R=0;
    int G=0;
    int B=0;
    color.setRgb(R,G,B);

    mBoundRect.adjust(0,0,unitAdd, unitAdd);
    shape.addEllipse(boundingRect());

}

void CreatureItem::drawSheep(qreal mWidth, qreal mHeight)
{
    int R=255;
    int G=255;
    int B=255;
    color.setRgb(R,G,B);

    mBoundRect.adjust(0,0,unitAdd, unitAdd);
    shape.addEllipse(boundingRect());
}

void CreatureItem::drawCow(qreal mWidth, qreal mHeight)
{
    int R=0;
    int G=0;
    int B=254;
    color.setRgb(R,G,B);

    mBoundRect.adjust(0,0,unitAdd, unitAdd);
    shape.addEllipse(boundingRect());
}


