#include "Shape.h"
#include <stdexcept>

Shape::Shape(char id, const Point arrayPoints[], int size)
	: _id(id),
	_size(size),
	_arc(new Point[_size])
{
	for (int i = 0; i < _size; i++)
	{
		_arc[i] = arrayPoints[i];
	}
}

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

Shape::~Shape()
{
	if (_arc)
	{
		delete[] _arc;
	} 
}