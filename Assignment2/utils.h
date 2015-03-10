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
		Point points[5000];
		Point closest;
	};

class utils
{
public:
	static double calculateDistance(Point a, Point b);

private:
	utils() {};


};
#endif