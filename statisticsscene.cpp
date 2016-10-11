#include "statisticsscene.h"

#include <iostream>

StatisticsScene::StatisticsScene()
{

}

StatisticsScene::StatisticsScene(qreal width, qreal height, int id)
    :QGraphicsScene(0, 0, width, height)
{
    speciesID = id;
    mWidth = width;
    mHeight = height;
    unitHeight = height / (qreal)(cntLines+1);
    unitWidth = (width-(qreal)boundWidth-(qreal)boundWidth-textWidth)/(qreal)(limitOfPoints);

    unitValue=1;   //For initialization
    currentNumber=0;
    cntNumber.clear();


    lineColor.setRed(0);
    lineColor.setGreen(255);
    lineColor.setBlue(0);
    textColor.setRed(255);
    textColor.setGreen(255);
    textColor.setBlue(255);

    this->setBackgroundBrush(Qt::black);
    this->setSceneRect(0,0,width,height);

    initialLines(width,height);
}

void StatisticsScene::sceneUpdate()
{
    this->clear();
    initialLines(mWidth, mHeight);

    int tempCnt = mCreatureVector.getCntBySpeciesID(speciesID);
    currentNumber++;
    cntNumber.push_back(tempCnt);

    if(currentNumber > limitOfPoints)
    {
        cntNumber.pop_front();
        currentNumber = limitOfPoints;
    }


    int tempMax = getMaxNumber();
    tempMax = tempMax + cntLines;
    unitValue = (int)(tempMax / cntLines);

    initialText();
    drawLines();
}

void StatisticsScene::initialLines(qreal width, qreal height)
{
    for(int i=1; i<=cntLines ;i++)
    {
        QLineF mLine((qreal)boundWidth+textWidth,
                     unitHeight*(qreal)i,
                     width-(qreal)boundWidth,
                     unitHeight*(qreal)i
                     );
        QGraphicsLineItem *line = new QGraphicsLineItem(mLine);
        line->setPen(QPen(textColor, linePenThickness, Qt::SolidLine, Qt::FlatCap));
        this->addItem(line);
    }    
}

void StatisticsScene::initialText()
{
    for(int i=1; i<=cntLines ;i++)
    {
        QPointF mPoint((qreal)boundWidth,mHeight-(qreal)i*unitHeight-unitHeight/2.0 );
        QString sValue =  QString::number(i*unitValue,10);
        QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem(sValue);
        text->setBrush(QBrush(textColor));
        text->setFont(QFont(QString("Consolas"),fontSize,QFont::Bold));
        text->setPos(mPoint);
        this->addItem(text);
    }

}

void StatisticsScene::drawLines()
{

    int i=0;
    std::list<int>::iterator it1 = cntNumber.begin();
    std::list<int>::iterator it2 = cntNumber.begin();
    it2++;
    if(cntNumber.size()==1) return;

    //std::cout<<"Vector Size : "<<cntNumber.size() <<std::endl;

    int maxValue = unitValue * cntLines;
    qreal dValue = unitHeight*(qreal)cntLines/(qreal)maxValue;

    for(;it2 != cntNumber.end(); )
    {
        QLineF mLine((qreal)boundWidth + textWidth + unitWidth/2.0 + (qreal)i*unitWidth,
                     mHeight- dValue*(*it1),
                     (qreal)boundWidth + textWidth + unitWidth/2.0 + (qreal)(i+1)*unitWidth,
                     mHeight- dValue*(*it2)
                     );

        QGraphicsLineItem *line = new QGraphicsLineItem(mLine);
        line->setPen(QPen(lineColor, dataPenThickness, Qt::SolidLine, Qt::FlatCap));
        this->addItem(line);

        it2++;
        it1++;
        i++;
    }


    /*  For Test:

    int maxValue = unitValue * cntLines;
    qreal dValue = unitHeight*(qreal)cntLines/(qreal)maxValue;
    int i=1;
    QLineF mLine((qreal)boundWidth + textWidth + unitWidth/2.0 + (qreal)i*unitWidth,
                 mHeight- dValue*10,
                 (qreal)boundWidth + textWidth + unitWidth/2.0 + (qreal)(i+1)*unitWidth,
                 mHeight- dValue*2
                 );

    QGraphicsLineItem *line = new QGraphicsLineItem(mLine);
    line->setPen(QPen(lineColor, penThickness, Qt::SolidLine, Qt::FlatCap));
    this->addItem(line);
    */

}

int StatisticsScene::getMaxNumber()
{
    int tempMax=0;
    std::list<int>::iterator it = cntNumber.begin();

    for( ; it!=cntNumber.end() ; it++)
    {
        if(tempMax < (*it))
        {
            tempMax=(*it);
        }
    }

    return tempMax;
}

