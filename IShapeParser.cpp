#include "IShapeParser.h"
#include "TriangleParser.h"
#include "RectangleParser.h"

IShapeParser* IShapeParser::createParser(const std::string& str)
{
	if (str == "Triangle")
	{
		return new TriangleParser();
	}

	if (str == "Rectangle")
	{
		return new RectangleParser();
	}

	throw std::invalid_argument("Bad argument!");
}