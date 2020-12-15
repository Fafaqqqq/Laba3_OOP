#pragma once
#include "IShapeParser.h"

class ParserBase : public IShapeParser
{
public:
	Shape* parse() const override;
private:
	virtual const char* getMessage() const = 0;
	virtual Shape* scan() const = 0;
	
};