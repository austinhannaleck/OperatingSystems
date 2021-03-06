#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"

class Controller
{

public:
	Controller();
	Point getRefPoint();
	Point* getAllPoints();
	void calculatePoints(int& process, package * pBuff, int& c);
	
	Point closestPoints[100];
	
	void getUserInput();
	void generatePoints();

private:
	Point refPoint;
	Point allPoints[500000];
	

};
#endif