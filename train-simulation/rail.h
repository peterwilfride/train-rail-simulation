#ifndef RAIL_H
#define RAIL_H

#include <QPoint>
#include <QColor>
#include <QPainter>
#include <QPaintEvent>

class Rail
{
public:
    Rail(QPoint pi, QPoint pf);
    void draw(QPainter *shape, QColor color);
    int lenght();
    QPoint getStart();
    QPoint getFinish();
    QChar getOrientation();
private:
    QPoint pi;
    QPoint pf;
};

#endif // RAIL_H
