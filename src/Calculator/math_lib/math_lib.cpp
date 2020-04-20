/**
  * @file math_lib.cpp
  * @author Jakub Kolb, Matej Turek
  * @brief Matematické funkce programu
  */

#include "math_lib.h"

/**
   * Funkce součtu 
   *
   * @param x První číslo operace
   * @param y Druhé číslo operace
   * @return Vraci x + y
   */


double math_lib::addition (double x, double y)
{
    return x + y;
}


/**
   * Funkce rozdílu 
   *
   * @param x První číslo operace
   * @param y Druhé číslo operace
   * @return Vraci x - y
   */
double math_lib::subtraction (double x, double y)
{
    return x - y;
}

/**
   * Funkce dělení 
   *
   * @param x První číslo operace
   * @param y Druhé číslo operace
   * @return Vraci x / y
   */

double math_lib::division (double x, double y)
{
    if(y==0){
        throw std::logic_error("Nelze dělit 0");
    }
    return x / y;
}

/**
   * Funkce násobené 
   *
   * @param x První číslo operace
   * @param y Druhé číslo operace
   * @return Vraci x * y
   */

double math_lib::multiplication (double x, double y)
{
    return x * y;
}

/**
   * Funkce faktorial 
   *
   * @param x První číslo operace
   * @return Vraci x!
   */

double math_lib::factorial (double x)
{
    if (x < 0)
    {
        return 0;
    }
    if(x > 160){
        throw std::logic_error("Velké číslo na faktorial");
    }
    if (x > 1)
    {
        return x * factorial(x - 1);
    }
    else
    {
        return 1;
    }
}


/**
   * Funkce mocnina 
   *
   * @param x První číslo operace
   * @param y Druhé číslo operace
   * @return Vraci x^y
   */

double math_lib::power (double x, double y)
{
    if (y == 0) {
        return 1;
    }

    if (y < 0) {
        return 0;
    }

    double result=1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }

    return result;
}


/**
   * Funkce odmocnina 
   *
   * @param x První číslo operace
   * @param y Druhé číslo operace
   * @return Vraci x sqrt(y)
   */

double math_lib::root (double x, double y)
{
    if (y <= 0)
    {
        return 0;
    }
    else
    {
        return std::pow(x, 1.0/y);
    }
}
