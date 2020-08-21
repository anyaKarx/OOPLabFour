#include "DoubleValidator.h"
#include <exception>

bool DoubleValidator::IsValuePositive(double value)
{
	return value > 0;
}

bool DoubleValidator::IsValueInRangle(double value, double min, double max)
{
	return (value > min && value < max);
}

void DoubleValidator::AssertPositiveValue(double value)
{
	if (!IsValuePositive(value))
	{
		throw std::exception(
			"Значение меньше нуля");
	}
}

void DoubleValidator::AssertValueInRangle(double value, double min, double max)
{
	if (!IsValueInRangle(value, min, max))
	{
		throw std::exception(
			"Значение вне диапозона");
	}
}