#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{

public:
	Point getRefPoint();

private:
	Point allPoints[int size];
	Point closestPoints[int n];
	Point refPoint();

};
#endif