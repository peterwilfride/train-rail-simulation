#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "train.h"
#include "rail.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void move(QPainter train);

protected:
    virtual void paintEvent(QPaintEvent *e);

private slots:
    void TimerSlotTrail1();

    void TimerSlotTrail2();

    void TimerSlotTrail3();

    void on_pushButton_clicked();

    void on_yellow_horizontalSlider_sliderMoved(int position);

    void on_blue_horizontalSlider_sliderMoved(int position);

    void on_red_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    Train* yellow_train;
    Train* blue_train;
    Train* red_train;

    Rail* rail1;
    Rail* rail2;
    Rail* rail3;
    Rail* rail4;
    Rail* rail5;
    Rail* rail6;
    Rail* rail7;
    Rail* rail8;
    Rail* rail9;
    Rail* rail10;

    QTimer* timer_train1;
    QTimer* timer_train2;
    QTimer* timer_train3;

    int basetime;
};
#endif // MAINWINDOW_H
