#include "Operations.h"
#include "Vector2D.h"

double Operations::compareArea(const Shape& obj_1, const Shape& obj_2)
{
	return obj_1.getArea() - obj_2.getArea();
}

double Operations::radiusDifference(const Shape& obj_1, const Shape& obj_2)
{
	obj_1.checkFigure();
	obj_2.checkFigure();

	Vector2D f_diagonal(obj_1.atPoint(0).getX() - obj_1.atPoint(2).getX(),
						obj_1.atPoint(0).getY() - obj_1.atPoint(2).getY());

	Vector2D s_diagonal(obj_1.atPoint(1).getX() - obj_1.atPoint(3).getX(),
						obj_1.atPoint(1).getY() - obj_1.atPoint(3).getY());

	return f_diagonal.length() / 2. - s_diagonal.length() / 2.;
}
