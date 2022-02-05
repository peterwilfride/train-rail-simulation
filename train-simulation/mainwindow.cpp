#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include "rail.h"
#include "train.h"
#include <QTime>
#include <thread>
#include <functional>
#include <QThread>

Train* yellow_train;
Train* blue_train;
Train* red_train;

QPoint pos_train1, pos_train2, pos_train3;
int t_train1, t_train2, t_train3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rail1 = new Rail(QPoint(10, 10), QPoint(10, 230));
    rail2 = new Rail(QPoint(10, 10), QPoint(390, 10));
    rail5 = new Rail(QPoint(390, 10), QPoint(790, 10));
    rail6 = new Rail(QPoint(790, 10), QPoint(790, 230));
    rail9 = new Rail(QPoint(10,470), QPoint(790,470));
    rail8 = new Rail(QPoint(790,230), QPoint(790,470));
    rail10 = new Rail(QPoint(10,230), QPoint(10,470));
    rail3 = new Rail(QPoint(390,10), QPoint(390,230));
    rail4 = new Rail(QPoint(10,230), QPoint(390,230));
    rail7 = new Rail(QPoint(390,230), QPoint(790,230));

    yellow_train = new Train(rail1);
    blue_train = new Train(rail6);
    red_train = new Train(rail8);

    basetime = 100;
    t_train1 = basetime;
    t_train2 = basetime;
    t_train3 = basetime;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delay(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::sendPosTrain1(int px, int py)
{
    pos_train1.setX(px);
    pos_train1.setY(py);
}

void MainWindow::sendPosTrain2(int px, int py)
{
    pos_train2.setX(px);
    pos_train2.setY(py);
}

void MainWindow::sendPosTrain3(int px, int py)
{
    pos_train3.setX(px);
    pos_train3.setY(py);
}

int MainWindow::sendTimeTrain1()
{
    return t_train1;
}

int MainWindow::sendTimeTrain2()
{
    return t_train2;
}

int MainWindow::sendTimeTrain3()
{
    return t_train3;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter shape(this);

    // rails
    // yellow
    rail1->draw(&shape, Qt::yellow);
    rail2->draw(&shape, Qt::yellow);

    // blue
    rail5->draw(&shape, Qt::blue);
    rail6->draw(&shape, Qt::blue);

    // red
    rail8->draw(&shape, Qt::red);
    rail9->draw(&shape, Qt::red);
    rail10->draw(&shape, Qt::red);

    // black - shared
    rail3->draw(&shape, Qt::black);
    rail4->draw(&shape, Qt::black);
    rail7->draw(&shape, Qt::black);

    // trains
    yellow_train->draw(&shape, Qt::yellow);
    blue_train->draw(&shape, Qt::blue);
    red_train->draw(&shape, Qt::red);


    // set positions of trains
    yellow_train->setPos(pos_train1.x(), pos_train1.y());
    blue_train->setPos(pos_train2.x(), pos_train2.y());
    red_train->setPos(pos_train3.x(), pos_train3.y());

    update();
}


void MainWindow::on_yellow_horizontalSlider_sliderMoved(int position)
{
    t_train1 = basetime/position;
}


void MainWindow::on_blue_horizontalSlider_sliderMoved(int position)
{
    t_train2 = basetime/position;
}


void MainWindow::on_red_horizontalSlider_sliderMoved(int position)
{
    t_train3 = basetime/position;
}

