#include "taskwindow2.h"
#include "ui_taskwindow2.h"

taskwindow2::taskwindow2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::taskwindow2)
{
    ui->setupUi(this);
}

taskwindow2::~taskwindow2()
{
    delete ui;
}

void taskwindow2::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText(); // Получаем текст из QTextEdit

    if(checkFirstLabel(text)) //
        ui->label_4->setText("Верно");
    else
        ui->label_4->setText("Неверно");
}


void taskwindow2::on_pushButton_2_clicked()
{
    QString text = ui->textEdit_2->toPlainText(); // Получаем текст из QTextEdit

    if(checkSecondLabel(text)) //
        ui->label_5->setText("Верно");
    else
        ui->label_5->setText("Неверно");
}

