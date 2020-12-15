#include "Triangle.h"
#include "Vector2D.h"

Triangle::Triangle(const Point* arrayPoints)
	: Shape('R', arrayPoints, 3) {}

const char* Triangle::info() const
{
	return "This is a Triangle!";
}

double Triangle::getArea() const
{
	checkFigure();

	Vector2D f_line(atPoint(0).getX() - atPoint(1).getX(),
					atPoint(0).getY() - atPoint(1).getY());

	Vector2D s_line(atPoint(0).getX() - atPoint(2).getX(),
					atPoint(0).getY() - atPoint(2).getY());

	Vector2D t_line(atPoint(1).getX() - atPoint(2).getX(),
					atPoint(1).getY() - atPoint(2).getY());

	double half_perimeter = (f_line.length() + s_line.length() + t_line.length()) / 2;
	double f = (f_line.length() - half_perimeter);
	double s = (s_line.length() - half_perimeter);
	double t = (t_line.length() - half_perimeter);

	/*return sqrt(half_perimeter * (f_line.length() - half_perimeter)
							   * (s_line.length() - half_perimeter)
							   * (t_line.length() - half_perimeter));*/
	return sqrt(half_perimeter * f * s * t);
}

void Triangle::checkFigure() const
{
	Vector2D f_line(atPoint(0).getX() - atPoint(1).getX(),
					atPoint(0).getY() - atPoint(1).getY());

	Vector2D s_line(atPoint(0).getX() - atPoint(2).getX(),
					atPoint(0).getY() - atPoint(2).getY());

	Vector2D t_line(atPoint(1).getX() - atPoint(2).getX(),
					atPoint(1).getY() - atPoint(2).getY());

	if (f_line.length() + s_line.length() < t_line.length() ||
		f_line.length() + t_line.length() < s_line.length() ||
		t_line.length() + s_line.length() < f_line.length())
	{
		throw std::logic_error("This isn`t rectangle!	");
	}
}