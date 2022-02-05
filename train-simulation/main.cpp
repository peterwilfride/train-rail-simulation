#include "mainwindow.h"
#include <QApplication>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <QDebug>

int px_1, px_2, px_3;
int py_1, py_2, py_3;
int v1, v2, v3;
                    //3     //4     //7
pthread_mutex_t mutex1, mutex2, mutex3;
void *thread_result;

pthread_t th1, th2, th3;

void* train1(void*);
void* train2(void*);
void* train3(void*);

int main(int argc, char *argv[])
{
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_mutex_init(&mutex3, NULL);

    v1 = 5; v2 = 5; v3 = 5;
    px_1 = 0; px_2 = 780; px_3 = 780;
    py_1 = 0; py_2 = 0; py_3 = 220;

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    pthread_create(&th1, NULL, train1, NULL);
    pthread_create(&th2, NULL, train2, NULL);
    pthread_create(&th3, NULL, train3, NULL);

    return a.exec();
}

void* train1(void*)
{
    while(true) {
        //qDebug() << "move no trilho 2";
        while(px_1 >= 0 && px_1 < 380 && py_1 == 0) {
            px_1 += v1;
            MainWindow::sendPosTrain1(px_1, py_1);
            qDebug() << MainWindow::sendTimeTrain1();
            MainWindow::delay(100);
        }
        //qDebug() << "move no trilho 3";
        pthread_mutex_lock(&mutex1);
        while(py_1 >= 0 && py_1 < 220 && px_1 == 380) {
            py_1 += v1;
            MainWindow::sendPosTrain1(px_1, py_1);
            MainWindow::delay(100);
        }
        pthread_mutex_unlock(&mutex1);
        //qDebug() << "move no trilho 4";
        pthread_mutex_lock(&mutex2);
        while(px_1 > 0 && px_1 <= 380 && py_1 == 220) {
            px_1 -= v1;
            MainWindow::sendPosTrain1(px_1, py_1);
            MainWindow::delay(100);
        }
        pthread_mutex_unlock(&mutex2);
        //qDebug() << "move no trilho 1";
        while(py_1 > 0 && py_1 <= 220 && px_1 == 0) {
            py_1 -= v1;
            MainWindow::sendPosTrain1(px_1, py_1);
            MainWindow::delay(100);
        }
    }
}

void* train2(void*)
{
    while(true) {
        //qDebug() << "move no trilho 6";
        while(py_2 >= 0 && py_2 < 220 && px_2 == 780) {
            py_2 += v2;
            MainWindow::sendPosTrain2(px_2, py_2);
            MainWindow::delay(100);
        }
        //qDebug() << "move no trilho 7";
        pthread_mutex_lock(&mutex3);
        while(px_2 > 380 && px_2 <= 780 && py_2 == 220) {
            px_2 -= v2;
            MainWindow::sendPosTrain2(px_2, py_2);
            MainWindow::delay(100);
        }
        pthread_mutex_unlock(&mutex3);
        //qDebug() << "move no trilho 3";
        pthread_mutex_lock(&mutex1);
        while(py_2 > 0 && py_2 <= 220 && px_2 == 380) {
            py_2 -= v2;
            MainWindow::sendPosTrain2(px_2, py_2);
            MainWindow::delay(100);
        }
        pthread_mutex_unlock(&mutex1);
        //qDebug() << "move no trilho 5";
        while(px_2 >= 380 && px_2 < 780 && py_2 == 0) {
            px_2 += v2;
            MainWindow::sendPosTrain2(px_2, py_2);
            MainWindow::delay(100);
        }
    }
}

void* train3(void*)
{
    while(true) {
        //qDebug() << "move no trilho 8";
        while(py_3 >= 220 && py_3 < 460 && px_3 == 780) {
            py_3 += v3;
            MainWindow::sendPosTrain3(px_3, py_3);
            MainWindow::delay(100);
        }
        //qDebug() << "move no trilho 9";
        while(px_3 > 0 && px_3 <= 780 && py_3 == 460) {
            px_3 -= v3;
            MainWindow::sendPosTrain3(px_3, py_3);
            MainWindow::delay(100);
        }
        //qDebug() << "move no trilho 10";
        while(py_3 > 220 && py_3 <= 460 && px_3 == 0) {
            py_3 -= v3;
            MainWindow::sendPosTrain3(px_3, py_3);
            MainWindow::delay(100);
        }
        //qDebug() << "move no trilho 4";
        pthread_mutex_lock(&mutex2);
        while(px_3 >= 0 && px_3 < 380 && py_3 == 220) {
            px_3 += v3;
            MainWindow::sendPosTrain3(px_3, py_3);
            MainWindow::delay(100);
        }
        pthread_mutex_unlock(&mutex2);
        //qDebug() << "move no trilho 7";
        pthread_mutex_lock(&mutex3);
        while(px_3 >= 380 && px_3 < 780 && py_3 == 220) {
            px_3 += v3;
            MainWindow::sendPosTrain3(px_3, py_3);
            MainWindow::delay(100);
        }
        pthread_mutex_unlock(&mutex3);
    }
}

