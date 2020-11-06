#include "Point.h"

Point::Point(double x, double y)
	:_x(x), _y(y) {}

Point::Point(const Point& other)
	: _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
	{
		return *this;
	}

	_x = other._x;
	_y = other._y;
}

double Point::getX()
{
	return _x;
}

double Point::getY()
{
	return _y;
}

void Point::move(const Point& other)
{
	_x = other._x;
	_y = other._y;
}

void Point::move(double x, double y)
{
	_x += x;
	_y += y;
}
