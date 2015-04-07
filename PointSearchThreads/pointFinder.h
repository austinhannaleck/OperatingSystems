#ifndef POINTFINDER_H
#define POINTFINDER_H

struct Point
{
	int x;
	int y;
};

class pointFinder
{
public:
	void getUserInput();
	//generate points
	//get refPoint
	//getAllPoints
	//closest point

private:
	int numPoints;
	Point ref;
	Point points[5000];
	Point closest;

};
#endif