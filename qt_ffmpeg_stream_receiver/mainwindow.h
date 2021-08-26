#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define __STDC_CONSTANT_MACROS
#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QScrollBar>
#include <QThread>
#include <QImage>
#include "worker.h"
#include "global.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotNewImage1(QImage image);
    void slotNewImage2(QImage image);
    void slotNewImage3(QImage image);
    void slotNewImage4(QImage image);
    void slotNewImage5(QImage image);
    void slotNewImage6(QImage image);
    void slotNewImage7(QImage image);
    void slotNewImage8(QImage image);
    void slotNewImage9(QImage image);

private:
    Ui::MainWindow *ui;
    Worker *work1;
    Worker *work2;
    Worker *work3;
    Worker *work4;
    Worker *work5;
    Worker *work6;
    Worker *work7;
    Worker *work8;
    Worker *work9;
    QThread *thread1;
    QThread *thread2;
    QThread *thread3;
    QThread *thread4;
    QThread *thread5;
    QThread *thread6;
    QThread *thread7;
    QThread *thread8;
    QThread *thread9;

    //QProcess *mTranscodingProcess;
};

#endif // MAINWINDOW_H
