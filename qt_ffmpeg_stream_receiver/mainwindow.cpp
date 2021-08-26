#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread1 = new QThread(this);
    thread2 = new QThread(this);
    thread3 = new QThread(this);
    thread4 = new QThread(this);
    thread5 = new QThread(this);
    thread6 = new QThread(this);
    thread7 = new QThread(this);
    thread8 = new QThread(this);
    thread9 = new QThread(this);

    connect(this,&MainWindow::destroyed,thread1,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread2,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread3,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread4,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread5,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread6,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread7,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread8,&QThread::quit);
    connect(this,&MainWindow::destroyed,thread9,&QThread::quit);

    work1   = new Worker();
    work1->moveToThread(thread1);
    work1->rtpUrl = rtpUrl1;
    thread1->start();

    work2   = new Worker();
    work2->moveToThread(thread2);
    work2->rtpUrl = rtpUrl2;
    thread2->start();

    work3   = new Worker();
    work3->moveToThread(thread3);
    work3->rtpUrl = rtpUrl3;
    thread3->start();

    work4   = new Worker();
    work4->moveToThread(thread4);
    work4->rtpUrl = rtpUrl4;
    thread4->start();

    work5   = new Worker();
    work5->moveToThread(thread5);
    work5->rtpUrl = rtpUrl5;
    thread5->start();

    work6   = new Worker();
    work6->moveToThread(thread6);
    work6->rtpUrl = rtpUrl6;
    thread6->start();

    work7   = new Worker();
    work7->moveToThread(thread7);
    work7->rtpUrl = rtpUrl7;
    thread7->start();

    work8   = new Worker();
    work8->moveToThread(thread8);
    work8->rtpUrl = rtpUrl8;
    thread8->start();

    work9   = new Worker();
    work9->moveToThread(thread9);
    work9->rtpUrl = rtpUrl9;
    thread9->start();

    //connect(ui->pushButton,&QPushButton::clicked,work1,&Worker::get_stream);
    connect(ui->pushButton,&QPushButton::clicked,work1,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread1,&QThread::quit);
    connect(work1,&Worker::sig_new_frame,this,&MainWindow::slotNewImage1);

    connect(ui->pushButton,&QPushButton::clicked,work2,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread2,&QThread::quit);
    connect(work2,&Worker::sig_new_frame,this,&MainWindow::slotNewImage2);

    connect(ui->pushButton,&QPushButton::clicked,work3,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread3,&QThread::quit);
    connect(work3,&Worker::sig_new_frame,this,&MainWindow::slotNewImage3);

    connect(ui->pushButton,&QPushButton::clicked,work4,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread4,&QThread::quit);
    connect(work4,&Worker::sig_new_frame,this,&MainWindow::slotNewImage4);

    connect(ui->pushButton,&QPushButton::clicked,work5,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread5,&QThread::quit);
    connect(work5,&Worker::sig_new_frame,this,&MainWindow::slotNewImage5);

    connect(ui->pushButton,&QPushButton::clicked,work6,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread6,&QThread::quit);
    connect(work6,&Worker::sig_new_frame,this,&MainWindow::slotNewImage6);

    connect(ui->pushButton,&QPushButton::clicked,work7,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread7,&QThread::quit);
    connect(work7,&Worker::sig_new_frame,this,&MainWindow::slotNewImage7);

    connect(ui->pushButton,&QPushButton::clicked,work8,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread8,&QThread::quit);
    connect(work8,&Worker::sig_new_frame,this,&MainWindow::slotNewImage8);

    connect(ui->pushButton,&QPushButton::clicked,work9,&Worker::get_images_from_streem);
    connect(this,&MainWindow::destroyed,thread9,&QThread::quit);
    connect(work9,&Worker::sig_new_frame,this,&MainWindow::slotNewImage9);

}

MainWindow::~MainWindow()
{
    thr_work=false;
    thread2->quit();
    thread3->quit();
    thread1->quit();
    thread4->quit();
    thread5->quit();
    thread6->quit();
    thread7->quit();
    thread8->quit();
    thread9->quit();
    QThread::sleep(3);
    delete ui;
}

void MainWindow::slotNewImage1(QImage image)
{
    image = image.scaled(ui->label->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label->setPixmap(pixmap);
}

void MainWindow::slotNewImage2(QImage image)
{
    image = image.scaled(ui->label_2->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_2->setPixmap(pixmap);
}

void MainWindow::slotNewImage3(QImage image)
{
    image = image.scaled(ui->label_3->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_3->setPixmap(pixmap);
}

void MainWindow::slotNewImage4(QImage image)
{
    image = image.scaled(ui->label_4->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_4->setPixmap(pixmap);
}

void MainWindow::slotNewImage5(QImage image)
{
    image = image.scaled(ui->label_5->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_5->setPixmap(pixmap);
}

void MainWindow::slotNewImage6(QImage image)
{
    image = image.scaled(ui->label_6->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_6->setPixmap(pixmap);
}

void MainWindow::slotNewImage7(QImage image)
{
    image = image.scaled(ui->label_7->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_7->setPixmap(pixmap);
}

void MainWindow::slotNewImage8(QImage image)
{
    image = image.scaled(ui->label_8->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_8->setPixmap(pixmap);
}

void MainWindow::slotNewImage9(QImage image)
{
    image = image.scaled(ui->label_9->size());
    QPixmap pixmap = QPixmap::fromImage(image);
    ui->label_9->setPixmap(pixmap);
}

