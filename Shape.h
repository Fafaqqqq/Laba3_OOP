#pragma once
#include "Point.h" 


class Shape 
{
public:
	Shape() = default;
	Shape(char id, const Point arrayPoints[], int size);

	virtual const char* info() const = 0;
	virtual double getArea() const = 0;
	virtual void checkFigure() const = 0;
	virtual ~Shape();

	const Point& atPoint(int index) const;
private:
	char _id = 0;
	int _size = 0;
	Point* _arc = nullptr;
};