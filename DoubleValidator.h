#pragma once

static class DoubleValidator
{
public:
	static bool IsValuePositive(double value);
	static bool IsValueInRangle(double value, double min, double max);

	static void AssertPositiveValue(double value);
	static void AssertValueInRangle(double value, double min, double max);
};