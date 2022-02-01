#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include "rail.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
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
}

void MainWindow::TimerSlotTrail1()
{
    yellow_train->move(rail2, 1);
    yellow_train->move(rail3, -1);
    yellow_train->move(rail4, -1);
    yellow_train->move(rail1, 1);
    update();
}

void MainWindow::TimerSlotTrail2()
{
    blue_train->move(rail6, -1);
    blue_train->move(rail7, -1);
    blue_train->move(rail3, 1);
    blue_train->move(rail5, 1);
    update();
}

void MainWindow::TimerSlotTrail3()
{
    red_train->move(rail8, -1);
    red_train->move(rail9, -1);
    red_train->move(rail10, 1);
    red_train->move(rail4, 1);
    red_train->move(rail7, 1);
    update();
}

void MainWindow::on_pushButton_clicked()
{
    timer_train1 = new QTimer(this);
    timer_train2 = new QTimer(this);
    timer_train3 = new QTimer(this);

    connect(timer_train1, &QTimer::timeout, this, &MainWindow::TimerSlotTrail1);
    connect(timer_train2, &QTimer::timeout, this, &MainWindow::TimerSlotTrail2);
    connect(timer_train3, &QTimer::timeout, this, &MainWindow::TimerSlotTrail3);

    timer_train1->start(basetime);
    timer_train2->start(basetime);
    timer_train3->start(basetime);
}

void MainWindow::on_yellow_horizontalSlider_sliderMoved(int position)
{
    yellow_train->setTime(basetime/position);
    timer_train1->start(yellow_train->getTime());
}


void MainWindow::on_blue_horizontalSlider_sliderMoved(int position)
{
    blue_train->setTime(basetime/position);
    timer_train2->start(blue_train->getTime());
}


void MainWindow::on_red_horizontalSlider_sliderMoved(int position)
{
    red_train->setTime(basetime/position);
    timer_train3->start(red_train->getTime());
}

