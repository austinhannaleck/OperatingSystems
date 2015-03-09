#ifndef UTILS_H
#define UTILS_H

struct Point
{
	int x;
	int y;
};

struct package
	{
		int numPoints;
		Point ref;
		Point points[1];
		Point closest;
	};

int calculateDistance(Point a, Point b);

class utils
{
public:

private:


};
#endif