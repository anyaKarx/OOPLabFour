#include <iostream>
#include <vector>
#include <cassert>
#include <iterator>

#include "Detail.h"
#include "DoubleValidator.h"
#include "Rectangle.h"

void Rectangle::SetLength(double length)
{
	DoubleValidator::AssertPositiveValue(length);
	this->_length = length;
}

void Rectangle::SetWidth(double width)
{
	DoubleValidator::AssertPositiveValue(width);
	this->_width = width;
}

void Rectangle::SetCenter(double xCoordinate, double yCoordinate)
{
	this->_сenter =  Point(xCoordinate, yCoordinate);
}

Point Rectangle::GetPoint()
{
	return this->_сenter;
}

double Rectangle::GetLength()
{
	return this->_length;
}

double Rectangle::GetWidth()
{
	return this->_width;
}

Rectangle::Rectangle(double length, double width,
	double xCoordinate, double yCoordinate)
{
	try 
	{
		this->SetLength(length);
		this->SetWidth(width);
		this->SetCenter(xCoordinate, yCoordinate);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void DemoRectangleWithPoint()
{
	std::vector<Rectangle> rectangles;
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		rectangles.push_back(Rectangle(tools::random(1, 50),
			tools::random(1, 50), tools::random(-20, 20),
			tools::random(-20, 20)));
	}
	std::copy(rectangles.begin(), rectangles.end(),
		std::ostream_iterator<Rectangle>(std::cout, "\n"));

	double meanX = 0;
	double meanY = 0;
	for (auto i : rectangles)
	{
		meanX = meanX + i.GetPoint().GetX() / (uint16_t)rectangles.size();
		meanY = meanY + i.GetPoint().GetY() / (uint16_t)rectangles.size();
	}
	Point meanCenter = Point(meanX, meanY);
	std::cout << "\n Среднее значение всех центров: " << meanCenter << std::endl;
}