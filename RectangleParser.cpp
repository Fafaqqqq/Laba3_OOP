#include "RectangleParser.h"
#include "Scanner.h"
#include "Rectangle.h"

const char* RectangleParser::getMessage() const
{
	return "Enter four points of Rectangle (x, y): ";
}

std::unique_ptr<Shape> RectangleParser::scan() const
{
	const int size = 4;
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

	return std::make_unique<Rectangle>(name, arrayOfPoints);
}
