/**
  * @file main.cpp
  * @author Jakub Kolb, Matej Turek
  * @brief Hlavní funkce programu
  */


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
