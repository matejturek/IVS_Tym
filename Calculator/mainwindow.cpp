#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math_lib.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
    wait_for_operator= false;
    calc_operator = none;
    dot = false;
}

void MainWindow::digit_pressed()
{
    if(wait_for_operator==false && dot == false){
        ui->label->clear();
    }
    QPushButton *button = (QPushButton*)sender();
    double num = (ui->label->text() + button->text()).toDouble();
    QString string;
    string = QString::number(num, 'g', 15);
    ui->label->setText(string);

    wait_for_operator=true;
    dot = false;
}

//TODO:
void MainWindow::calc(en_operator op, double x, double y)
{
    math_lib ml;
    double res=0;
    switch(op){
        case none: break;
        case plus:  res=ml.addition(x,y); break;
        case minus: res=ml.subtraction(x,y); break;
        case power: res = ml.power(x,2); break;
        case root: res = ml.root(x,2);break;
        case divide: res= ml.division(x,y);break;
        case multiply: res = ml.multiplication(x,y); break;
    }
    calc_operator = none;
    sum_res = QString::number(res);
    sum_tmp = sum_res;
}
void MainWindow::on_pushButton_dot_released()
{
    if (!ui->label->text().contains(".")){
        ui->label->setText(ui->label->text() + tr("."));
        wait_for_operator = false;
        dot = true;
    }

}

void MainWindow::on_pushButton_equal_released()
{
    if(wait_for_operator == true){
        calc(calc_operator,sum_tmp.toDouble(),ui->label->text().toDouble());
        ui->label->setText(sum_res);
    }
}

void MainWindow::on_pushButton_plus_released()
{
    if(wait_for_operator==true){
        if(calc_operator != none ){
            on_pushButton_equal_released();
        }else{
            sum_tmp = ui->label->text();
        }
        calc_operator = plus;
        wait_for_operator=false;
    }
}

void MainWindow::on_pushButton_minus_released()
{
    if(wait_for_operator==true){
        if(calc_operator != none ){
            on_pushButton_equal_released();
        }else{
            sum_tmp = ui->label->text();
        }
        calc_operator = minus;
        wait_for_operator=false;
    }
}

void MainWindow::on_pushButton_multiply_released()
{
    if(wait_for_operator==true){
        if(calc_operator != none ){
            on_pushButton_equal_released();
        }else{
            sum_tmp = ui->label->text();
        }
        calc_operator = multiply;
        wait_for_operator=false;
    }
}

void MainWindow::on_pushButton_divide_released()
{
    if(wait_for_operator==true){
        if(calc_operator != none ){
            on_pushButton_equal_released();
        }else{
            sum_tmp = ui->label->text();
        }
        calc_operator = divide;
        wait_for_operator=false;
    }
}

void MainWindow::on_pushButton_power_released()
{
    if(wait_for_operator==true){
        if(calc_operator == none ){
            sum_tmp = ui->label->text();
            calc_operator = power;
            on_pushButton_equal_released();
        }else{
          on_pushButton_equal_released();
            sum_tmp = ui->label->text();
            calc_operator = power;
            on_pushButton_equal_released();
        }

    }
}

void MainWindow::on_pushButton_sqrt_released()
{
    if(wait_for_operator==true){
        if(calc_operator == none ){
            sum_tmp = ui->label->text();
            calc_operator = root;
            on_pushButton_equal_released();
        }else{
          on_pushButton_equal_released();
            sum_tmp = ui->label->text();
            calc_operator = root;
            on_pushButton_equal_released();
        }

    }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->label->clear();
}
