#pragma once
#include "Shape.h"

class IShapeParser
{
public:
	virtual Shape* parse() const = 0;
};