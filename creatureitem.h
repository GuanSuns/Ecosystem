#ifndef CREATUREITEM_H
#define CREATUREITEM_H

#include <QtGui>
#include <QColor>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>
#include <cmath>

#include "Ecosystem/Parameters.h"

class CreatureItem : public QGraphicsItem
{
public:
    CreatureItem();
    CreatureItem(qreal mWidth, qreal mHeight, int kind);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void drawWater(qreal mWidth, qreal mHeight);
    void drawGrass(qreal mWidth, qreal mHeight);
    void drawTiger(qreal mWidth, qreal mHeight);
    void drawWolf(qreal mWidth, qreal mHeight);
    void drawSheep(qreal mWidth, qreal mHeight);
    void drawCow(qreal mWidth, qreal mHeight);


private:
    QColor color;
    QPainterPath shape;
    QRectF mBoundRect;
    //QPixmap picture;

    static const int unitAdd;

};

#endif // CREATUREITEM_H
