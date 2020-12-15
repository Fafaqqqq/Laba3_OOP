#include "TriangleParser.h"
#include "Scanner.h"
#include "Triangle.h"

const char* TriangleParser::getMessage() const
{
	return "Enter three points of Triangle in the format { x, y }: ";
}

std::unique_ptr<Shape> TriangleParser::scan() const
{
	const int size = 3;
	Point arrayOfPoints[size];

	for (int i = 0; i < size; i++)
	{
		double x, y;

		Scanner().Scan(std::cin, "{ %f, %f }", &x, &y);

		arrayOfPoints[i] = Point(x, y);
	}

	return std::make_unique<Triangle>(arrayOfPoints);
}


