#ifndef TRAIN_H
#define TRAIN_H

#include "rail.h"

class Train
{
public:
    Train(QRect dim);
    void draw(QPainter *shape, QColor color);
    int getVel();
    void setVel(int vel);
    QPoint getPos();
    void setPos(int x, int y);
    void move();
private:
    int x;
    int y;
    int w;
    int h;
    int vel;
};

#endif // TRAIN_H
