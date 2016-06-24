#pragma once

double PowerWithUnsingnedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsingnedExponent(base,exponent>>1);
	result *= result;
	if (exponent & 0x1 == 1)
		result *= base;

	return result;
}

void Test()
{
	PowerWithUnsingnedExponent(2,3);
}