/**
  * @file mainwindow.cpp
  * @author Jakub Kolb, Matej Turek
  * @brief Hlavní okno programu
  */


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

    ui->pushButton_plus->setToolTip("Sčítání");
    ui->pushButton_minus->setToolTip("Odečítání");
    ui->pushButton_divide->setToolTip("Dělení");
    ui->pushButton_multiply->setToolTip("násobení");
    ui->pushButton_factorial->setToolTip("Faktorial");
    ui->pushButton_power->setToolTip("Druhá mocnina");
    ui->pushButton_power_y->setToolTip("Mocnina");
    ui->pushButton_sqrt->setToolTip("Druhá odmocnina");
    ui->pushButton_sqrt_y->setToolTip("Odmocnina");
    ui->pushButton_clear->setToolTip("Vymazání");
    ui->pushButton_equal->setToolTip("Vyhodnotit");
}

MainWindow::~MainWindow()
{
    delete ui;
    wait_for_operator= false;
    calc_operator = none;
    dot = false;
}
 /**
   * Metoda obsluhu tlačítek po stisknutí. Podle aktuálního stavu mění stav displayu (vyčistí nebo vypisuje čísla) 
   */

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

 /**
   * Metoda výpočtu. Podle zvolené operace zavolá operaci na výpočet výsledku. Výsledek náledně vypíše na display. 
   *
   * @param op Zvolená operace (například součet, rozdíl, ...)
   * @param x První číslo operace
   * @param y Druhý číslo operace
   */


void MainWindow::calc(en_operator op, double x, double y)
{
    math_lib ml;
    double res=0;
    switch(op){
        case none: break;
        case plus:  res=ml.addition(x,y); break;
        case minus: res=ml.subtraction(x,y); break;
        case power: res = ml.power(x,2); break;
        case powery: res = ml.power(x,y); break;
        case root: res = ml.root(x,2);break;
        case rooty: res = ml.root(x,y);break;
        case divide: res= ml.division(x,y);break;
        case multiply: res = ml.multiplication(x,y); break;
        case factorial: res = ml.factorial(x); break;
    }

    calc_operator = none;
    sum_res = QString::number(res);
    sum_tmp = sum_res;
}


 /**
   * Metoda obsluhu tlačítka po stiskntí desetinný čárky. 
   */

void MainWindow::on_pushButton_dot_released()
{
    if (!ui->label->text().contains(".")){
        ui->label->setText(ui->label->text() + tr("."));
        wait_for_operator = false;
        dot = true;
    }

}

/**
   * Metoda obsluhu tlačítka po stiskntí výpočtu. 
   */


void MainWindow::on_pushButton_equal_released()
{
    if(wait_for_operator == true){
        try{
            calc(calc_operator,sum_tmp.toDouble(),ui->label->text().toDouble());
        }catch(std::logic_error e){
            ui->label->setText(e.what());
            calc_operator = none;
            return;
        }
        ui->label->setText(sum_res);
        calc_operator = none;
    }
}

/**
   * Metoda obsluhu tlačítka po stiskntí součtu. 
   */


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

/**
   * Metoda obsluhu tlačítka po stiskntí rozdílu. 
   */

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


/**
   * Metoda obsluhu tlačítka po stiskntí násobení. 
   */

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


/**
   * Metoda obsluhu tlačítka po stiskntí dělení. 
   */

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


/**
   * Metoda obsluhu tlačítka po stiskntí mocnina. 
   */

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

/**
   * Metoda obsluhu tlačítka po stiskntí odmocnina. 
   */

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


/**
   * Metoda obsluhu tlačítka po stiskntí faktoriál. 
   */

void MainWindow::on_pushButton_factorial_released(){
    if(wait_for_operator==true){
        if(calc_operator == none ){
            sum_tmp = ui->label->text();
            calc_operator = factorial;
            on_pushButton_equal_released();
        }else{
          on_pushButton_equal_released();
            sum_tmp = ui->label->text();
            calc_operator = factorial;
            on_pushButton_equal_released();
        }

    }
}


/**
   * Metoda obsluhu tlačítka po stiskntí y-tá mocnina. 
   */

void MainWindow::on_pushButton_power_y_released(){
    if(wait_for_operator==true){
        if(calc_operator != none ){
            on_pushButton_equal_released();
        }else{
            sum_tmp = ui->label->text();
        }
        calc_operator = powery;
        wait_for_operator=false;
    }
}


/**
   * Metoda obsluhu tlačítka po stiskntí y-tá odmocnina. 
   */

void MainWindow::on_pushButton_sqrt_y_released(){
    if(wait_for_operator==true){
        if(calc_operator != none ){
            on_pushButton_equal_released();
        }else{
            sum_tmp = ui->label->text();
        }
        calc_operator = rooty;
        wait_for_operator=false;
    }
}

/**
   * Metoda obsluhu tlačítka po stiskntí vyčistění. 
   */

void MainWindow::on_pushButton_clear_released()
{
    ui->label->clear();
}
