#include "rail.h"
#include "mainwindow.h"
#include <QDebug>

Rail::Rail(QPoint pi, QPoint pf)
{
    this->pi = pi;
    this->pf = pf;
}

void Rail::draw(QPainter *shape, QColor color)
{
    shape->setRenderHint(QPainter::Antialiasing, true);
    shape->setPen(QPen(color, 6));
    shape->drawLine(this->pi, this->pf);
}

int Rail::lenght()
{
    int xi = this->pi.x();
    int xf = this->pf.x();
    int yi = this->pi.y();
    int yf = this->pf.y();

    int h = abs(xf - xi) != 0 ? abs(xf - xi) : abs(yf - yi);
    return h;
}

QPoint Rail::getStart()
{
    return this->pi;
}

QPoint Rail::getFinish()
{
    return this->pf;
}

QChar Rail::getOrientation()
{
    if (this->pf.x() > this->pi.x()) {
        return 'H'; // horizontal
    }
    return 'V'; // vertical
}


