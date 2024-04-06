#ifndef TASKWINDOW3_H
#define TASKWINDOW3_H

#include <QDialog>
#include <iostream>
#include <regex>
#include <string>

namespace Ui {
class taskwindow3;
}

class taskwindow3 : public QDialog
{
    Q_OBJECT

public:
    explicit taskwindow3(QWidget *parent = nullptr);
    ~taskwindow3();
    bool checkFirstLabel(QString text){
        std::string clearText = text.toStdString();
        std::regex pattern1("^(?!.*101)[01]*$");
        return std::regex_match(clearText, pattern1);
    }
    enum State {
        START,
        COUNT_ZEROS,
        COUNT_ONES,
        ACCEPT,
        INVALID
    };
    bool checkSecondLabel(QString text){
        std::string clearText = text.toStdString();
        int countZeros = 0;
        int countOnes = 0;
        State state = START;

        for (char c : clearText) {
            switch (state) {
            case START:
                if (c == '0') {
                    state = COUNT_ZEROS;
                    countZeros++;
                }
                else if (c == '1') {
                    state = COUNT_ONES;
                    countOnes++;
                }
                else {
                    state = INVALID;
                }
                break;
            case COUNT_ZEROS:
                if (c == '0') {
                    countZeros++;
                }
                else if (c == '1') {
                    state = COUNT_ONES;
                    countOnes++;
                }
                else {
                    state = INVALID;
                }
                break;
            case COUNT_ONES:
                if (c == '0') {
                    state = COUNT_ZEROS;
                    countZeros++;
                }
                else if (c == '1') {
                    countOnes++;
                }
                else {
                    state = INVALID;
                }
                break;
            case INVALID:
                return false; // если нашли невалидный символ, сразу возвращаем false
            default:
                break;
            }
        }
        // Проверяем условие на префикс и наличие подстроки с последовательностью больше чем на 2
        if (countZeros != countOnes || (clearText.find("000") != std::string::npos || clearText.find("111") != std::string::npos)) {
            return false;
        }
        else{
            state = ACCEPT;
        }
        return state == ACCEPT;
    }

    bool checkThirdLabel(QString text){
        std::string clearText = text.toStdString();
        int countZeros = 0;
        int countOnes = 0;
        State state = START;

        for (char c : clearText) {
            switch (state) {
            case START:
                if (c == '0') {
                    state = COUNT_ZEROS;
                    countZeros++;
                } else if (c == '1') {
                    state = COUNT_ONES;
                    countOnes++;
                }
                break;
            case COUNT_ZEROS:
                if (c == '0') {
                    countZeros++;
                } else if (c == '1') {
                    state = START;
                    countOnes++;
                }
                break;
            case COUNT_ONES:
                if (c == '0') {
                    state = START;
                    countZeros++;
                } else if (c == '1') {
                    countOnes++;
                }
                break;
            default:
                break;
            }
        }

        if ((countZeros % 5 == 0) && (countOnes % 2 == 0)) {
            state = ACCEPT;
        }

        return (state == ACCEPT);
    }


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::taskwindow3 *ui;
};

#endif // TASKWINDOW3_H
