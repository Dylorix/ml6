#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include "rect.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        if ((count % 2) == 1) {
        tempX1=event->x();
        tempY1=event->y();
    } else if ((count % 2) == 0) {
        tempX2=event->x();
        tempY2=event->y();
        Rect *r;
        r = new Rect (tempX1, tempX2, tempY1, tempY2);
        rects.append(r);
    }
    count++;
    repaint();
    } else {
        for(Rect *r :rects)
        {
            if(r)
                if(r->contains(event->x(),event->y()) && !r->getIsColored()) {
                    intersection++;
                    //тут получаем координаты
                    if(intersection == 1) {
                        cX1=r->getX1();cX2=r->getX2();cY1=r->getY1();cY2=r->getY2();
                        lengthL=event->x()-r->getX1();
                        lengthR=r->getX2()-event->x();
                        lengthT=event->y()-r->getY1();
                        lengthB=r->getY2()-event->y();
                    } else {
                        if (lengthL > event->x()-r->getX1()) {
                            lengthL=event->x()-r->getX1();
                            cX1=r->getX1();
                        }
                        if (lengthR > r->getX2()-event->x()) {
                            lengthR=r->getX2()-event->x();
                            cX2=r->getX2();
                        }
                        if (lengthT > event->y()-r->getY1()) {
                            lengthT=event->y()-r->getY1();
                            cY1=r->getY1();
                        }
                        if (lengthB > r->getY2()-event->y()) {
                            lengthB=r->getY2()-event->y();
                            cY2=r->getY2();
                        }
                    }
                }
        }
        Rect *r;
        r = new Rect (cX1,cX2,cY1,cY2,true,intersection-1);
        rects.append(r);
        repaint();
        qDebug("Кол-во пересечений = %d",intersection-1);
        intersection=0;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    {
        for(Rect *r :rects)
            if(r)
                if(r->getIsColored()) {
                    r->Colordraw(&painter);
                } else {
                    r->draw(&painter);
          }
    }
}
