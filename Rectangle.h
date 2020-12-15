#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(const Point* arrayPoints);

	const char* info() const override;
	double getArea() const override;
	void checkFigure() const override;
};