#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    enum en_operator{ none, plus, minus, divide, multiply, power, root};
    Ui::MainWindow *ui;
    QString sum_res;
    QString sum_tmp;
    en_operator calc_operator;
    bool wait_for_operator;
    bool dot;

private slots:
    void digit_pressed();

    void calc(en_operator op,double x,double y);

    void on_pushButton_dot_released();
    void on_pushButton_equal_released();
    void on_pushButton_plus_released();
    void on_pushButton_minus_released();
    void on_pushButton_multiply_released();
    void on_pushButton_divide_released();
    void on_pushButton_power_released();
    void on_pushButton_sqrt_released();
    void on_pushButton_clear_released();
};


#endif // MAINWINDOW_H
