#ifndef TASKWINDOW6_H
#define TASKWINDOW6_H

#include <QDialog>
#include <iostream>
#include <string>
#include <regex>
#include <QLabel>

namespace Ui {
class taskwindow6;
}

class taskwindow6 : public QDialog
{
    Q_OBJECT

public:
    explicit taskwindow6(QWidget *parent = nullptr);
    ~taskwindow6();
    bool checkInput(const QString& text, const std::regex& pattern) {
        std::string clearText = text.toStdString();
        return std::regex_search(clearText, pattern);
    }

    void setLabelText(QLabel* label, bool result) {
        if (result)
            label->setText("Соответствует");
        else
            label->setText("Не Соответствует");
    }
    bool containsInvalidCharacters(const QString& text) {
        std::string clearText = text.toStdString();
        std::regex pattern("[^01]"); // регулярное выражение, которое ищет любой символ, не равный "0" или "1"
        return std::regex_search(clearText, pattern); // возвращает true, если найден хотя бы один символ, отличный от "0" или "1"
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::taskwindow6 *ui;
};

#endif // TASKWINDOW6_H
