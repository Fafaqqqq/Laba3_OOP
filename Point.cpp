#include "Point.h"
#include <iostream>

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

bool Point::operator==(const Point& other) const
{
	return _x == other._x && _y == other._y;
}

double Point::getX() const
{
	return _x;
}

double Point::getY() const
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

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "{ " << point._x << ", " << point._y << " }";
	return out;
}