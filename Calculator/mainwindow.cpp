#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    double num = (ui->label->text() + button->text()).toDouble();
    QString string;
    string = QString::number(num, 'g', 15);
    ui->label->setText(string);
}

//TODO:
void MainWindow::on_pushButton_dot_released()
{

}



void MainWindow::on_pushButton_equal_released()
{

}

void MainWindow::on_pushButton_plus_released()
{

}

void MainWindow::on_pushButton_minus_released()
{

}

void MainWindow::on_pushButton_multiply_released()
{

}

void MainWindow::on_pushButton_divide_released()
{

}

void MainWindow::on_pushButton_power_released()
{

}

void MainWindow::on_pushButton_sqrt_released()
{

}

void MainWindow::on_pushButton_clear_released()
{

}
