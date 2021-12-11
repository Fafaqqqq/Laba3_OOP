#include "Triangle.h"
#include "Vector2D.h"

Triangle::Triangle(const std::string& name, std::vector<Point>& arrayPoints)
	: Shape(name, arrayPoints) {}

const char* Triangle::info() const
{
	return "This is a Triangle!";
}

double Triangle::getArea() const
{

	double a = (atPoint(0).getX() - atPoint(2).getX()) *
			   (atPoint(1).getY() - atPoint(2).getY());
	double b = (atPoint(1).getX() - atPoint(2).getX()) *
		       (atPoint(0).getY() - atPoint(2).getY());

	return 0.5 * std::fabs(a - b);
}

void Triangle::checkFigure() const {}