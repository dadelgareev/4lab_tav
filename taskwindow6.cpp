#include "taskwindow6.h"
#include "ui_taskwindow6.h"

taskwindow6::taskwindow6(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::taskwindow6)
{
    ui->setupUi(this);
}

taskwindow6::~taskwindow6()
{
    delete ui;
}

void taskwindow6::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText(); // Получаем текст из QTextEdit

    std::regex pattern1(R"((.*)01(.*))"); // (*)01*
    std::regex pattern2("(?:101|001){1}");    // (0+1)01
    std::regex pattern3(R"(00(0+1)*)");   // 00(0+1)*


    if (containsInvalidCharacters(text)) {
        ui->label_4->setText("Ошибка введенных данных");
        ui->label_5->setText("Ошибка введенных данных");
        ui->label_6->setText("Ошибка введенных данных");
    }
    else{
        setLabelText(ui->label_4, checkInput(text, pattern1));
        setLabelText(ui->label_5, checkInput(text, pattern2));
        setLabelText(ui->label_6, checkInput(text, pattern3));
    }

}

