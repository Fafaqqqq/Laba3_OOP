#include "Vector2D.h"

Vector2D::Vector2D(double x, double y)
	: Point(x, y) {}

Vector2D::Vector2D(const Vector2D& other)
	: Point(other.getX(), other.getY()) {}

double Vector2D::length() const
{
	return sqrt(getX() * getX() + getY() * getY());
}

bool Vector2D::equalByLength(const Vector2D& other) const
{
	return length() == other.length();
}