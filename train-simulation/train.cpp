#include "train.h"
#include <QPainter>
#include <QDebug>

Train::Train(QRect dim)
{
    this->x = dim.x();
    this->y = dim.y();
    this->w = dim.width();
    this->h = dim.height();
    this->vel = 5;
    this->time = 100;
}

Train::Train(Rail* rail)
{
    QPoint p = rail->getStart();
    this->x = p.x()-10;
    this->y = p.y()-10;
    this->w = 20;
    this->h = 20;
    this->vel = 5;
    this->time = 100;
}

void Train::draw(QPainter *shape, QColor color)
{
    shape->setRenderHint(QPainter::Antialiasing, true);
    shape->setPen(QPen(Qt::black, 1));
    shape->setBrush(QBrush(color, Qt::SolidPattern));
    shape->drawRect(this->x, this->y, this->w, this->h);
}

int Train::getVel()
{
    return this->vel;
}

void Train::setVel(int vel)
{
    this->vel = vel;
}

QPoint Train::getPos()
{
    return QPoint(this->x, this->y);
}

void Train::setPos(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Train::getTime()
{
    return this->time;
}

void Train::setTime(int time)
{
    this->time = time;
}

void Train::move()
{
    // yellow
    if (this->x >= 0 && this->x <= 380 && this->y == 0) {
        // moveRight()
        this->x += this->vel;
    }
    if (this->y >= 0 && this->y <= 220 && this->x == 380) {
        // moveDown()
        this->y += this->vel;
    }
    if (this->x >= 0 && this->x <= 380 && this->y == 220) {
        // moveLeft()
        this->x -= this->vel;
    }
    if (this->y >= 0 && this->y <= 220 && this->x == 0) {
        // moveUp()
        this->y -= this->vel;
    }
}

void Train::move(Rail *rail, int dir)
{
    QChar ori = rail->getOrientation();
    QPoint start = rail->getStart();
    QPoint finish = rail->getFinish();

    if (ori == 'H') {
       if (this->x >= start.x()-10 && this->x <= finish.x()-10 && this->y == start.y()-10) {
           if (dir == 1)
            this->x += this->vel;
           else
            this->x -= this->vel;
       }
    } else {
        if (this->y >= start.y()-10 && this->y <= finish.y()-10 && this->x == start.x()-10) {
            if (dir == 1)
             this->y -= this->vel;
            else
             this->y += this->vel;
        }
    }
}
