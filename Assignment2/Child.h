#ifndef CHILD_H
#define CHILD_H

#include "utils.h"

struct xyz
	{
		int numPoints;
		Point ref;
		Point points[];
		Point closest;
	};
	
class Child
{

public:

	Child(int n, Point r, Point p[], Point c);

	

private:

};

#endif