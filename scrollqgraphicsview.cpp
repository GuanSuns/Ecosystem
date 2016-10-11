#include "scrollqgraphicsview.h"

namespace viewParameters
{
    double factor = 1.0 ;
    double threshold = 5.0 ;
}

ScrollQGraphicsView::ScrollQGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
    viewParameters::factor = 1.0 ;
}


void ScrollQGraphicsView::wheelEvent(QWheelEvent *event)
{
    double numDegrees = -event->delta() / 8.0;
    double numSteps = numDegrees / 15.0;
    double factor = std::pow(1.125, numSteps);

    viewParameters::factor = viewParameters::factor * factor;

    scale(factor, factor);
}

