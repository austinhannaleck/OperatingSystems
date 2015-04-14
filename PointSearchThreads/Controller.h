#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"
#include <vector>

class Controller
{

public:
	Controller();
	Point getRefPoint();
	void setRefPoint(int x, int y) { refPoint.x = x; refPoint.y = y; };
	Point* getAllPoints();
	void calculatePoints(int& process, package * pBuff, int& c);
	
	vector<Point> closest;
	
	void getUserInput();
	void generatePoints();

private:
	Point refPoint;
	Point allPoints[500000];
	

};
#endif