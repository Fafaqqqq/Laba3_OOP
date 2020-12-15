#include "RectangleParser.h"
#include "Scanner.h"
#include "Rectangle.h"

const char* RectangleParser::getMessage() const
{
	return "Enter four points of Rectangle in the format { x, y }: ";
}

Shape* RectangleParser::scan() const
{
	const int size = 4;
	Point arrayOfPoints[size];

	for (int i = 0; i < size; i++)
	{
		double x, y;

		Scanner().Scan(std::cin, "{ %f, %f }", &x, &y);

		arrayOfPoints[i] = Point(x, y);
	}

	return new Rectangle(arrayOfPoints);
}
