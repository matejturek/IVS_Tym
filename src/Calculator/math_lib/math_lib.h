#ifndef MATH_LIB_H
#define MATH_LIB_H

#include <cmath>
#include <stdexcept>

class math_lib
{
public:
    double addition (double x, double y);
    double subtraction (double x, double y);
    double division (double x, double y);
    double multiplication (double x, double y);
    double factorial (double x);
    double power (double x, double y);
    double root (double x, double y);
};

#endif // MATH_LIB_H
