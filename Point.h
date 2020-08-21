#pragma once
#include <iostream>
#include <iomanip>

class Point
{
private:
	double _x = 0;
	double _y= 0;

	void SetX(double x);
	void SetY(double y);

public:
	double GetX();
	double GetY();

	Point(double x, double y);
	Point() {}
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os.precision(3);
	return os << "X = " << std::setw(7) << point._x 
		<< "; Y = " << std::setw(7) << point._y << ";";
}