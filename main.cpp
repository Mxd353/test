#include <QtMath>
#include <QtWidgets>

#include "ball.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Ball *ball = new Ball;

    QGraphicsLineItem *line1 = new QGraphicsLineItem(0, 0, 0, 700);
    QGraphicsLineItem *line2 = new QGraphicsLineItem(0, 700, 700, 700);
    QGraphicsLineItem *line3 = new QGraphicsLineItem(700, 700, 700, 0);
    QGraphicsLineItem *line4 = new QGraphicsLineItem(700, 0, 0, 0);

    QGraphicsScene scene;
        scene.setItemIndexMethod(QGraphicsScene::NoIndex);
        scene.setSceneRect(0, 0, 700, 700);

    QGraphicsView view(&scene);
        view.setRenderHint(QPainter::Antialiasing);
        view.setCacheMode(QGraphicsView::CacheBackground);
        view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate );
        view.resize(750, 750);

        scene.addItem(line1);
        scene.addItem(line2);
        scene.addItem(line3);
        scene.addItem(line4);

        scene.addItem(ball);

        //随机方向
        qreal x = QRandomGenerator :: global() -> bounded( -300 , 300 );
        qreal y = QRandomGenerator :: global() -> bounded( -300 , 300 );
        //随机速度
        double xSpeed = QRandomGenerator :: global() -> bounded( -10 , 10 );
        double ySpeed = QRandomGenerator :: global() -> bounded( -10 , 10 );

        ball->setPos(x,y);
        ball->setSpeed(xSpeed,ySpeed);

        view.setWindowTitle("随机方向随机速度");
        view.show();


    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
    timer.start(1000/33);

    return app.exec();
}
