#include <cmath>

/* x + y */ 
public double addition (double x, double y)
{
	return x + y;
}

/* x - y */
public double subtraction (double x, double y)
{
	return x + y;
}

/* x % y */
public double division (double x, double y)
{
	return x % y;
}

/* x * y */
public double multiplication (double x, double y)
{
	return x * y;
}

/* x! */
public double factorial (double x) 
{
	if (x < 0)
	{
		return 0;
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
public double power (double x, double y) 
{
	if (y == 0) {
		return 1;
	}
	
	if (y < 0) {
		return 0;
	}
	
	double result;
	for (int i = 0; i < y; i++) 
	{
		result *= x;
	}
	
	return result;
}

/* y-th root of x */
public double root (double x, double y)
{
	if (y <= 0)
	{
		return 0;
	}
	else
	{
		return std::pow(value, 1.0/root);
	}
}