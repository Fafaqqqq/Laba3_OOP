#pragma once
#include "ParserBase.h"

class TriangleParser : public ParserBase
{
private:
	const char* getMessage() const override;
	Shape* scan() const override;
};
