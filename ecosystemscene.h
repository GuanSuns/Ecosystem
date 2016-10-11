#ifndef ECOSYSTEMSCENE_H
#define ECOSYSTEMSCENE_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "Ecosystem/MapItem.h"
#include "creatureitem.h"

class EcosystemScene : public QGraphicsScene
{
    Q_OBJECT

public:
    EcosystemScene();
    EcosystemScene(qreal width,qreal height);

    void reDraw();

private:
    qreal unitWidth;
    qreal unitHeight;
    //QPixmap pixBackground;

    QColor viewColor;

};

#endif // ECOSYSTEMSCENE_H
