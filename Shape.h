#pragma once
#include "Point.h"
#include <vector>

class Shape 
{
public:
	Shape() = default;
	Shape(const std::string& name, std::vector<Point>& arrayPoints);
	virtual ~Shape() = default;

	virtual const char* info() const = 0;
	virtual double getArea() const = 0;
	virtual void checkFigure() const = 0;

	const Point& atPoint(int index) const;
	const std::string& getName() const;
private:
	std::string _name = nullptr;
	int _size = 0;
	std::vector<Point> _arc;
};