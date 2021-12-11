#pragma once
#include "Point.h"

class Vector2D : public Point
{
public:
	Vector2D() = default;
	Vector2D(double x, double y);
	Vector2D(const Vector2D& other);

	bool equalByLength(const Vector2D& other) const;

	double length() const;
};