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
    yellow_train = new Train(QRect(0,0,20,20));
    blue_train = new Train(QRect(780,0,20,20));
    red_train = new Train(QRect(0,220,20,20));

    rail1 = new Rail(QPoint(10, 10), QPoint(10, 230));
    rail2 = new Rail(QPoint(10, 10), QPoint(390, 10));
    rail5 = new Rail(QPoint(390, 10), QPoint(790, 10));
    rail6 = new Rail(QPoint(790, 10), QPoint(790, 230));
    rail8 = new Rail(QPoint(10,470), QPoint(790,470));
    rail9 = new Rail(QPoint(790,230), QPoint(790,470));
    rail10 = new Rail(QPoint(10,230), QPoint(10,470));
    rail3 = new Rail(QPoint(390,10), QPoint(390,230));
    rail4 = new Rail(QPoint(10,230), QPoint(390,230));
    rail7 = new Rail(QPoint(390,230), QPoint(790,230));

    time_y = 100;
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

void MainWindow::TimerSlot()
{
    yellow_train->move();
    update();
}

void MainWindow::on_pushButton_clicked()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::TimerSlot);
    timer->start(time_y);
    qDebug() << time_y;
}

void MainWindow::on_yellow_horizontalSlider_sliderMoved(int position)
{
    time_y = 100/position;
    timer->start(time_y);
    qDebug() << time_y;
}

