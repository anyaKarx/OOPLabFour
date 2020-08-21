#pragma once
#include "Point.h"


class Rectangle
{
private:
	double _length = 0;
	double _width = 0;
	Point _ñenter;

public:
	void SetLength(double length);
	void SetWidth(double width);
	void SetCenter(double xCoordinate, double yCoordinate);
	
	Point GetPoint();
	double GetLength();
	double GetWidth();
	Rectangle(double length, double width, double xCoordinate, double yCoordinate);
	Rectangle() {};
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
};

inline std::ostream& operator<<(std::ostream& os , const Rectangle& rectangle)
{
	return os <<"Ñenter coordinates: "<< rectangle._ñenter 
		<< " Length = " << std::setw(5) <<rectangle._length
		<< "; Width = " << std::setw(5) << rectangle._width;
}
void DemoRectangleWithPoint();

