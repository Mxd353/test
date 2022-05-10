#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>

//! [0]
class Ball : public QGraphicsItem
{
public:
    Ball();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void setSpeed(double Xspeed, double Yspeed);

protected:
    void advance(int step) override;

private:
    int radius = 40;
    int po_x = 330;
    int po_y = 330;
    double xspeed;
    double yspeed;
};
//! [0]

#endif
