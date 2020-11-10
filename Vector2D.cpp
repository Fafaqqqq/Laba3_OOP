#include "Vector2D.h"

Vector2D::Vector2D(double x, double y)
	: Point(x, y) {}

Vector2D::Vector2D(const Vector2D& other)
	: Point(other.getX(), other.getY()) {}

double Vector2D::length()
{
	return sqrt(getX() * getX() + getY() * getY());
}