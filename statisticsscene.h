#ifndef STATISTICSSCENE_H
#define STATISTICSSCENE_H

#include <QGraphicsScene>

#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QPointF>
#include <QFont>
#include <QString>
#include <QLineF>
#include <list>

#include "Ecosystem/MapItem.h"
#include "Ecosystem/CreatureVector.h"

class StatisticsScene : public QGraphicsScene
{
     Q_OBJECT

public:
    StatisticsScene();
    StatisticsScene(qreal width,qreal height, int id);
    void sceneUpdate();

private:
    const int cntLines = 5;
    const int textWidth = 15;
    const int fontSize = 8;
    const int boundWidth = 2;
    const int dataPenThickness = 2 ;
    const int linePenThickness = 1;
    const int limitOfPoints = 40;

    int speciesID;
    std::list<int> cntNumber;
    int currentNumber;

    qreal unitWidth;
    qreal unitHeight;
    qreal mWidth;
    qreal mHeight;
    int unitValue;

    QColor lineColor;
    QColor textColor;

    void initialLines(qreal width, qreal height);
    void initialText();
    void drawLines();
    int getMaxNumber();
};

#endif // STATISTICSSCENE_H
