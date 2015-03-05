#include <iostream>
#include <cmath>

#include "utils.h"

using namespace std;

int utils::calculateDistance(Point a, Point b)
{
	int result = 0;

	return sqrt(pow(a.x - b.x, 2) + pow(a.y, b.y));
}