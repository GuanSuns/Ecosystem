#ifndef SCROLLQGRAPHICSVIEW_H
#define SCROLLQGRAPHICSVIEW_H

#include <QtGui>
#include <QGraphicsView>
#include <cmath>

namespace viewParameters
{
    extern double factor;
    extern double threshold;
}

class ScrollQGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    ScrollQGraphicsView(QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *event);
};

#endif // SCROLLQGRAPHICSVIEW_H
