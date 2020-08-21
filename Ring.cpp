#include "Ring.h"
#include "Detail.h"
#include <iostream>
#include <exception>
#include <string>

#include "DoubleValidator.h"

int Ring::AllRingsCount = 0;


void Ring::SetRadiuses(double outer, double inner)
{
	DoubleValidator::AssertPositiveValue(outer);
	DoubleValidator::AssertValueInRangle(inner, 0, outer);

	this->_outerRadius = outer;
	this->_innerRadius = inner;
}

void Ring::SetCenter(double x, double y)
{
	this->_center = Point(x, y);
}

Point Ring::GetCenter()
{
	return this->_center;
}

double Ring::GetOuterRadius()
{
	return this->_outerRadius;
}

double Ring::GetInnerRadius()
{
	return this->_innerRadius;
}

double Ring::GetArea()
{
	return (PI * this->GetOuterRadius()
		* this->GetOuterRadius()) -
		(PI * this->GetInnerRadius()
			* this->GetInnerRadius());
}

int Ring::GetAllRingsCount()
{
	return AllRingsCount;
}

Ring::Ring(double outer, double inner, double x, double y)
{
	try { this->SetRadiuses(outer, inner); }
	catch (std::exception e) { std::cout << e.what(); };
	this->SetCenter(x, y);
	AllRingsCount++;
}

Ring::~Ring()
{
	AllRingsCount--;
}

void DemoRing()
{
	/*
	Ring ring1 = Ring(-2.0, 1.0, 5.0, 7.2);
	Ring ring2 = Ring(3.0, -2.0, 9.0, 2.2);
	*/
	std::cout << "Количество колец до вызова конструктора: "
		<< Ring::GetAllRingsCount() << std::endl;

	Ring* ring1 = new Ring(2.0, 1.0, 5.0, 7.2);
	Ring* ring2 = new Ring(3.0, 2.0, 9.0, 2.2);
	std::cout << "Площадь первого кольца: " << ring1->GetArea()
		<< "\nПлощадь второго кольца: " << ring2->GetArea();

	std::cout << "\nКоличество колец после вызова конструктора: "
		<< Ring::GetAllRingsCount() << std::endl;
	delete ring1;
	std::cout << "Количество колец после вызова деструктора: "
		<< Ring::GetAllRingsCount() << std::endl;
	delete ring2;
}