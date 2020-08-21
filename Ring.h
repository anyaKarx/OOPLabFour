#pragma once
#include "Point.h"

class Ring
{
private:
	const double PI = 3.14159;
	static int AllRingsCount;

	double _outerRadius;
	double _innerRadius;
	Point _center;

public:

	void SetRadiuses(double outer, double inner);
	void SetCenter(double x, double y);

	Point GetCenter();
	double GetOuterRadius();
	double GetInnerRadius();
	static int GetAllRingsCount();

	double GetArea();

	Ring(double outer, double inner, double x, double y);
	~Ring(); 
	friend std::ostream& operator<<(std::ostream& os, const Ring& ring);
};

inline std::ostream& operator<<(std::ostream& os, const Ring& ring)
{
	return os << "Ñenter coordinates: " << ring._center
		<< " Outer radius = " << std::setw(5) << ring._outerRadius
		<< "; Inner radius = " << std::setw(5) << ring._innerRadius;
}

void DemoRing();