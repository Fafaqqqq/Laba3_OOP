#pragma once
#include "IShapeParser.h"

class ParserBase : public IShapeParser
{
public:
	std::unique_ptr<Shape> parse() const override;
private:
	virtual const char* getMessage() const = 0;
	virtual std::unique_ptr<Shape> scan() const = 0;
	
};