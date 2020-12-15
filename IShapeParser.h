#pragma once
#include "Shape.h"

class IShapeParser
{
public:
	virtual std::unique_ptr<Shape> parse() const = 0;

	static IShapeParser* createParser(const std::string& str);
};