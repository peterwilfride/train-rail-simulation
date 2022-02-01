#ifndef TRAIN_H
#define TRAIN_H

#include "rail.h"

class Train
{
public:
    Train(QRect dim);
    Train(Rail* rail);
    void draw(QPainter *shape, QColor color);
    int getVel();
    void setVel(int vel);
    QPoint getPos();
    void setPos(int x, int y);
    int getTime();
    void setTime(int time);
    void move();
    void move(Rail* rail, int dir);
private:
    int x;
    int y;
    int w;
    int h;
    int vel;
    int time;
};

#endif // TRAIN_H
