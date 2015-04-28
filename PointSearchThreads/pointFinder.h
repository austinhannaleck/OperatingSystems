#ifndef POINTFINDER_H
#define POINTFINDER_H

#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

class pointFinder
{
public:
	pointFinder(){};
	void getUserInput();
	vector<Point> closest;
	void generatePoints();
	Point getRefPoint() { return ref; };
	Point ref;
	Point allPoints[500000];

private:
	int numPoints;

};
#endif