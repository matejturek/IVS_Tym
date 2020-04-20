/**
  * @file main.cpp
  * @author David Sladký
  * @brief Standart deviation
  * @details Contains program to calculate standart deviation for profiling math_lib.
  */

#include <vector>
#include <iostream>

#include "math_lib.h"

/**
 * @brief Calculates Standart deviation from numbers on standar input.
 * @return 0 as exit code and calculated standart deviation on stdout.
 */
int main()
{
    std::vector<int> numbers; /** Vector holding all input numbers */
    math_lib math;
    double n = 0; /**< Holds number to be saved into vector */
    double am = 0; /**< Arithmetic Mean */
    double sum = 0; /**< Sum of powers */
    double sd = 0; /**< Standart Deviation */
    double tmp = 0;

    while(std::cin >> n) /**< Loads all numbers into vector. */
    {
        numbers.push_back(n);
    }

    if(numbers.size() == 0) /**< If no number was loaded, then exit program and return 0. */
    {
        std::cout << 0;
        return 0;
    }

    for(size_t i = 0; i < numbers.size(); i++) /**< Calculates arithmetic mean and sum of all numbers to power 2 */
    {
        am = math.addition(am, numbers[i]);

        tmp = math.power(numbers[i], 2);
        sum = math.addition(sum, tmp);
    }
    am = math.division(am, numbers.size()); /**< Divine summed numbers by they amount to get arithmetic mean */
    am = math.power(am, 2); /**< power arithmetic mean to 2 for standart deviation */
    am = math.multiplication(numbers.size(), am); /**< multiply mean by amount of numbers for standart deviation */

    tmp = math.subtraction(numbers.size(), 1); /**< N - 1 */
    tmp = math.division(1, tmp); /**< 1 / (N - 1) */

    sd = math.subtraction(sum, am);
    sd = math.multiplication(tmp, sd);
    sd = math.root(sd, 2);

    std::cout << sd;
    return 0;
}

/*** End of file main.cpp */
