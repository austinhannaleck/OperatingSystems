#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"

class Controller
{

public:
	Controller();
	Point getRefPoint();

private:
	Point allPoints[];
	Point closestPoints[];
	Point refPoint;

};
#endif