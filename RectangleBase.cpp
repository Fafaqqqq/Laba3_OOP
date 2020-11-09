#include "RectangleBase.h"
#include "PermutationPoints.h"

double RectangleBase::getArea()
{
	checkFigure();
	return 4;
}

void RectangleBase::checkFigure()
{
	PermutationPoints().permutation(getArc(), 4);
}