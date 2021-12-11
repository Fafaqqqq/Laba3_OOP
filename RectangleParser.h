#pragma once
#include "ParserBase.h"

class RectangleParser : public ParserBase
{
private:
	const char* getMessage() const override;
	std::unique_ptr<Shape> scan() const override;
};