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
	void getUserInput();
	vector<Point> closest;
	void generatePoints();
	//get refPoint
	//getAllPoints
	//closest point

private:
	int numPoints;
	Point ref;
	Point points[5000];
	Point allPoints[500000];
	//Point closest;

};
#endif