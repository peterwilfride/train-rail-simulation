#include "train.h"
#include <QPainter>

Train::Train(QRect dim)
{
    this->x = dim.x();
    this->y = dim.y();
    this->w = dim.width();
    this->h = dim.height();
    this->vel = 5;
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
