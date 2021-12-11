#include "Shape.h"
#include <stdexcept>

Shape::Shape(const std::string& name, std::vector<Point>& arrayPoints)
	: _name(name),
	_size(arrayPoints.size()),
	_arc(std::move(arrayPoints)) {}

const Point& Shape::atPoint(int index) const
{
	if (0 <= index && index < _size)
	{
		return _arc[index];
	}
	else
	{
		throw std::range_error("No such element!");
	}
}

const std::string& Shape::getName() const
{
	return _name;
}
