/**
  * @file main.cpp
  * @author David Sladký
  * @brief Calculates Standart deviation from numbers on standar input.
  */

#include <vector>
#include <iostream>

#include "math_lib.h"

int main()
{
    std::vector<int> numbers; /** Vector holding all input numbers */
    math_lib math;
    double n = 0; /** Holds number to be saved into vector */
    double am = 0; /** Arithmetic Mean */
    double sum = 0; /** Sum of powers */
    double sd = 0; /** Standart Deviation */
    double tmp = 0;

    // Load all numbers
    while(std::cin >> n)
    {
        numbers.push_back(n);
    }

    // if no number loaded, return 0
    if(numbers.size() == 0)
    {
        std::cout << 0;
        return 0;
    }

    // calculate Arithmetic mean (am) and sum of all numbers to power 2 (2)
    for(size_t i = 0; i < numbers.size(); i++)
    {
        am = math.addition(am, numbers[i]); // add number to total

        tmp = math.power(numbers[i], 2); // number power 2
        sum = math.addition(sum, tmp); // add powered number to sum
    }
    am = math.division(am, numbers.size()); // divide summed numbers for final arithmetic mean
    am = math.power(am, 2); // power mean to 2 for standart deviation
    am = math.multiplication(numbers.size(), am); // multiply mean by amount of numbers for standart deviation

    tmp = math.subtraction(numbers.size(), 1); // N - 1
    tmp = math.division(1, tmp); // 1 / (N - 1)

    sd = math.subtraction(sum, am);
    sd = math.multiplication(tmp, sd);
    sd = math.root(sd, 2);

    std::cout << sd;
    return 0;
}

/*** End of file main.cpp */
