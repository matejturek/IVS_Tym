#include "math_lib.h"

double math_lib::addition (double x, double y)
{
    return x + y;
}

double math_lib::subtraction (double x, double y)
{
    return x - y;
}

/* x / y */
double math_lib::division (double x, double y)
{
    if(y==0){
        throw std::logic_error("Nelze dělit 0");
    }
    return x / y;
}

/* x * y */
double math_lib::multiplication (double x, double y)
{
    return x * y;
}

/* x! */
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

/* x^y */
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

/* y-th root of x */
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
