#pragma once
#include <cmath>

//template to calculate the greatest common denominator of two numbers
template <typename T>
T gcd(T value1, T value2)
{
	T greatest = 1; // current greatest common divisor, 1 is minimum

					  // loop from 2 to smaller of x and y
	for (int i = 2; i <= ((abs(value1) < abs(value2)) ? abs(value1) : abs(value2)); i++)
	{
		// if current i divides both x and y
		if (value1 % i == 0 && value2 % i == 0)
		{
			greatest = i; // update greatest common divisor
		}
	} // end for

	return greatest; // return greatest common divisor found
}
