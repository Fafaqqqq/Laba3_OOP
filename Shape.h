#pragma once
#include "Point.h" 

class Shape 
{
public:
	Shape() = default;
	Shape(char id, const Point arrayPoints[]);

	virtual const char* info() = 0;
	virtual double getArea() = 0;
	virtual ~Shape();

	Point& atPoint(int index);

private:
	char _id = '0';
	int _size = 0;
	Point* _arc = nullptr;
};