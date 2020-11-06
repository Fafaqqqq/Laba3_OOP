#include "Shape.h"
#include <stdexcept>

Shape::Shape(char id, const Point arrayPoints[])
	: _id(id),
	_size(sizeof(arrayPoints) / sizeof(Point)),
	_arc(new Point[_size])
{
	for (int i = 0; i < _size; i++)
	{
		_arc[i] = arrayPoints[i];
	}
}

Point& Shape::atPoint(int index)
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

Shape::~Shape()
{
	if (_arc)
	{
		delete[] _arc;
	} 
}