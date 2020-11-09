#pragma once
#include "Shape.h"

class RectangleBase : public Shape
{
private:
	double getArea() override;
	void checkFigure() override;
};