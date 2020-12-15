#pragma once
#include "ParserBase.h"

class RectangleParser : public ParserBase
{
private:
	const char* getMessage() const override;
	Shape* scan() const override;
};