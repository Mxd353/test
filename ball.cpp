#include "ball.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <QtMath>
#include <QGraphicsRectItem>
#include <QDebug>

Ball::Ball()
{}

QRectF Ball::boundingRect() const
{
    qreal penWidth=1;
    return QRectF(po_x - penWidth / 2, po_y - penWidth / 2,
                  radius + penWidth, radius + penWidth);
}

QPainterPath Ball::shape() const
{
    QPainterPath path;
    path.addRect(po_x, po_y, radius, radius);
    return path;
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::red : Qt::green);//碰撞检测
    painter->drawEllipse(po_x, po_y, radius, radius);
}
//! [3]

//! [4]
void Ball::advance(int step)
{
    if(!step)
        return;

       if(!collidingItems().isEmpty()) //碰撞检测函数
        {
           if(x() <= -330  || x() >= 330)xspeed*=-1;
           if(y() <= -330  || y() >= 330)yspeed*=-1;
        }
            moveBy(xspeed, yspeed);
}

void Ball::setSpeed(double Xspeed, double Yspeed)
{
    xspeed = Xspeed;
    yspeed = Yspeed;
}
