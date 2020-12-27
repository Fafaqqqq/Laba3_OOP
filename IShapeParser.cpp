#include "IShapeParser.h"
#include "TriangleParser.h"
#include "RectangleParser.h"

std::unique_ptr<IShapeParser> IShapeParser::createParser(const std::string& str)
{
	if (str == "Triangle")
	{
		return std::make_unique<TriangleParser>();
	}

	if (str == "Rectangle")
	{
		return std::make_unique<RectangleParser>();
	}

	throw std::invalid_argument("Bad argument!");
}