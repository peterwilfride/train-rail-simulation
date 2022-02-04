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

    static void delay(int n);

    static void sendPosTrain1(int px, int py);
    static void sendPosTrain2(int px, int py);
    static void sendPosTrain3(int px, int py);

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

protected:
    virtual void paintEvent(QPaintEvent *e);

private slots:
    /*
    void on_yellow_horizontalSlider_sliderMoved(int position);

    void on_blue_horizontalSlider_sliderMoved(int position);

    void on_red_horizontalSlider_sliderMoved(int position);*/

private:
    Ui::MainWindow *ui;

    int basetime;
};
#endif // MAINWINDOW_H
