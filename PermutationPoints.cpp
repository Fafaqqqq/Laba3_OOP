#include "PermutationPoints.h"
#include <cmath>
#include <algorithm>

void PermutationPoints::permutation(Point* arrayPoints, int len)
{
	/*bool flag = true;

	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < len; j++)
		{
			if (j != i)
			{
				Vector2D firstLine(arrayPoints[0].getX() - arrayPoints[i].getX(),
					arrayPoints[0].getY() - arrayPoints[i].getY());

				Vector2D secondLine(arrayPoints[j].getX() - arrayPoints[i].getX(),
					arrayPoints[j].getY() - arrayPoints[i].getY());

				double check = fabs(firstLine.getX() * secondLine.getX() +
					firstLine.getY() * secondLine.getY());

				if (!check)
				{
					if (i == 2 && j == 1)
					{
						std::swap(arrayPoints[j], arrayPoints[i]);
					}
					else
					{
						std::swap(arrayPoints[1], arrayPoints[i]);
						std::swap(arrayPoints[2], arrayPoints[j]);
					}
					return;
				}
			}
		}
	}*/

	int i_min = 0;

	for (int i = 1; i < len; i++)
	{
		if (arrayPoints[i].getX() <= arrayPoints[i_min].getX() &&
			arrayPoints[i].getY() < arrayPoints[i_min].getY() || 
			arrayPoints[i].getX() < arrayPoints[i_min].getX() &&
			arrayPoints[i].getY() <= arrayPoints[i_min].getY())
		{
			i_min = i;
		}
	}

	std::swap(arrayPoints[0], arrayPoints[i_min]);
}