#include "rect.h"
#include <QPainter>
#include <QColor>

Rect::Rect()
{

}

int Rect::getX1() const
{
    return x1;
}

void Rect::setX1(int newX1)
{
    x1 = newX1;
}

int Rect::getX2() const
{
    return x2;
}

void Rect::setX2(int newX2)
{
    x2 = newX2;
}

int Rect::getY1() const
{
    return y1;
}

void Rect::setY1(int newY1)
{
    y1 = newY1;
}

int Rect::getY2() const
{
    return y2;
}

void Rect::setY2(int newY2)
{
    y2 = newY2;
}

void Rect::draw(QPainter *painter)
{
    QBrush brush (QColor(0,0,0,0));
    painter->setBrush(brush);
    painter->drawRect(x1,y1,abs(x1-x2),abs(y1-y2));
}

void Rect::Colordraw(QPainter *painter)
{
    switch (color) {
    case -1:
        c1=0; c2=0; c3=0; c4=0;
        break;
    case 0:
        c1=0; c2=0; c3=0; c4=0;
        break;
    case 1:
        c1=255; c2=0; c3=0; c4=255;
        break;
    case 2:
        c1=255; c2=255; c3=0; c4=255;
        break;
    case 3:
        c1=0; c2=255; c3=0; c4=255;
        break;
    case 4:
        c1=0; c2=0; c3=255; c4=255;
        break;
    default:
        c1=0; c2=0; c3=0; c4=255;
        break;
    }
    QBrush brush (QColor(c1,c2,c3,c4));
    painter->setBrush(brush);
    painter->drawRect(x1,y1,abs(x1-x2),abs(y1-y2));
}

bool Rect::getIsColored() const
{
    return isColored;
}

void Rect::setIsColored(bool newIsColored)
{
    isColored = newIsColored;
}
