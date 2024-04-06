#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QDialog>
#include <iostream>
#include <regex>
#include <string>

namespace Ui {
class taskWIndow;
}

class taskWIndow : public QDialog
{
    Q_OBJECT

public:
    explicit taskWIndow(QWidget *parent = nullptr);
    ~taskWIndow();
    bool checkFirstLabel(QString text){
        std::string clearText = text.toStdString();
        std::regex pattern1(".*a.*b.*|.*b.*a.*");
        return std::regex_match(clearText, pattern1);
    }
    bool checkSecondLabel(QString text){
        std::string clearText = text.toStdString();
        std::regex pattern1(".*1.{9}$");
        return std::regex_match(clearText, pattern1);
    }
    bool checkThirdLabel(QString text){
        std::string clearText = text.toStdString();
        std::regex pattern1("^(?!.*111)(?!.*11.*11).*$");
        return std::regex_match(clearText, pattern1);
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::taskWIndow *ui;
};

#endif // TASKWINDOW_H
