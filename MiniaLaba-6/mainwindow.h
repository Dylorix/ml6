#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rect.h"
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    int count = 1,intersection = 0; //Кол-во пересечений
    QVector<Rect *>rects;
    int tempX1,tempX2,tempY1,tempY2; //Временные координаты для создания прямоугольника
    int cX1,cX2,cY1,cY2,lengthL,lengthR,lengthT,lengthB; //Координаты для закрашеваемой обасти и расстояния от клика до потенциальных стен
};
#endif // MAINWINDOW_H
