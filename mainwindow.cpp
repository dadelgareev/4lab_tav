#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskwindow.h"
#include "taskwindow2.h"
#include "taskwindow3.h"
#include "taskwindow6.h"

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

void MainWindow::on_pushButton_3_clicked()
{
    taskWIndow task_window;
    task_window.setModal(true);
    task_window.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    taskwindow2 task_window;
    task_window.setModal(true);
    task_window.exec();
}


void MainWindow::on_pushButton_clicked()
{
    taskwindow3 task_window;
    task_window.setModal(true);
    task_window.exec();
}


void MainWindow::on_pushButton_6_clicked()
{
    taskwindow6 task_window;
    task_window.setModal(true);
    task_window.exec();
}

