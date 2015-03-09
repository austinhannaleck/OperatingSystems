#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"

class Controller
{

public:
	Controller();
	Point getRefPoint();
	Point* getAllPoints();
	Point* calculatePoints(int& process);
	
	Point closestPoints[100];
	
	void getUserInput();
	void generatePoints();

private:
	Point refPoint;
	Point allPoints[10];
	

};
#endif