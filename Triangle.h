#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle() = default;
	Triangle(const std::string& name, std::vector<Point>& arrayPoints);

	const char* info() const override;
	double getArea() const override;
	void checkFigure() const override;
};