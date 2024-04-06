#include "taskwindow3.h"
#include "ui_taskwindow3.h"

taskwindow3::taskwindow3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::taskwindow3)
{
    ui->setupUi(this);
}

taskwindow3::~taskwindow3()
{
    delete ui;
}
void taskwindow3::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText(); // Получаем текст из QTextEdit

    if(checkFirstLabel(text)) //
        ui->label_5->setText("Верно");
    else
        ui->label_5->setText("Неверно");
}


void taskwindow3::on_pushButton_2_clicked()
{
    QString text = ui->textEdit_2->toPlainText(); // Получаем текст из QTextEdit

    if(checkSecondLabel(text)) //
        ui->label_6->setText("Верно");
    else
        ui->label_6->setText("Неверно");
}


void taskwindow3::on_pushButton_3_clicked()
{
    QString text = ui->textEdit_3->toPlainText(); // Получаем текст из QTextEdit

    if(checkThirdLabel(text)) //
        ui->label_7->setText("Верно");
    else
        ui->label_7->setText("Неверно");
}
