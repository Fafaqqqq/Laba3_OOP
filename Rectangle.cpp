#include "Rectangle.h"
#include "Vector2D.h"

Rectangle::Rectangle(const Point* arrayPoints)
	: Shape('R', arrayPoints, 4) {}

const char* Rectangle::info() const
{
	return "This is a Rectangle!";
}

double Rectangle::getArea() const
{
	checkFigure();

	Vector2D f_line(atPoint(0).getX() - atPoint(1).getX(), atPoint(0).getY() - atPoint(1).getY());
	Vector2D s_line(atPoint(0).getX() - atPoint(3).getX(), atPoint(0).getY() - atPoint(3).getY());

	return f_line.length() * s_line.length();
}

void Rectangle::checkFigure() const
{
	Vector2D f_diagonal(atPoint(0).getX() - atPoint(2).getX(), atPoint(0).getY() - atPoint(2).getY());
	Vector2D s_diagonal(atPoint(1).getX() - atPoint(3).getX(), atPoint(1).getY() - atPoint(3).getY());

	if (f_diagonal.length() != s_diagonal.length())
	{
		throw std::logic_error("This isn`t rectangle!");
	}
}