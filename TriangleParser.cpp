#include "TriangleParser.h"
#include "Scanner.h"
#include "Triangle.h"

const char* TriangleParser::getMessage() const
{
	return "Enter three points of Triangle (x, y): ";
}

std::unique_ptr<Shape> TriangleParser::scan() const
{
	const int size = 3;
	std::vector<Point> arrayOfPoints;

	for (int i = 0; i < size; i++)
	{
		double x, y;

		Scanner().Scan(std::cin, "%f %f", &x, &y);

		arrayOfPoints.push_back(Point(x, y));
	}
	std::cout << "Enter name of shape: ";

	std::string name;
	Scanner().Scan(std::cin, "%s", &name);

	return std::make_unique<Triangle>(name, arrayOfPoints);
}


