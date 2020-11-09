#include "Point.h"
#include "PermutationPoints.h"

int main()
{
	Point arr[4] = { { 3, 1 },{ 2, 2 }, { 1, 2 }, { 1, 1 } };

	PermutationPoints().permutation(arr, 4);

	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	return 0;
}

