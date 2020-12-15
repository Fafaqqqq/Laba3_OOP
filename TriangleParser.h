#pragma once
#include "ParserBase.h"

class TriangleParser : public ParserBase
{
private:
	const char* getMessage() const override;
	std::unique_ptr<Shape> scan() const override;
};
