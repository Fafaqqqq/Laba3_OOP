#include "IShapeParser.h"
#include "TriangleParser.h"
#include "RectangleParser.h"

std::unique_ptr<IShapeParser> IShapeParser::createParser(char str)
{
	if (str == 'T')
	{
		return std::make_unique<TriangleParser>();
	}

	if (str == 'R')
	{
		return std::make_unique<RectangleParser>();
	}

	throw std::invalid_argument("Bad argument!");
}