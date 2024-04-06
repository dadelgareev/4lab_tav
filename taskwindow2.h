#ifndef TASKWINDOW2_H
#define TASKWINDOW2_H

#include <QDialog>
#include <iostream>
#include <regex>
#include <string>

namespace Ui {
class taskwindow2;
}

class taskwindow2 : public QDialog
{
    Q_OBJECT

public:
    explicit taskwindow2(QWidget *parent = nullptr);
    ~taskwindow2();
    bool checkFirstLabel(QString text){
        std::string clearText = text.toStdString();
        std::regex pattern1("^(?:(?:0+|1+)(?:0+|1+)*010101(?:0+|1+)*|010101(?:0+|1+)*)(?:0+|1+)?$");
        return std::regex_match(clearText, pattern1);
    }

    bool checkSecondLabel(QString text){
        std::string clearText = text.toStdString();
        std::regex pattern1("((1*)(0)(1*)(0)(1*)(0)(1*)(0)(1*)(0)(1*))*");
        return std::regex_match(clearText, pattern1);
    }
    private slots:
        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

    private:
    Ui::taskwindow2 *ui;
};

#endif // TASKWINDOW2_H
