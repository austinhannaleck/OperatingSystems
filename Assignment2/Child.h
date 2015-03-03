#ifndef CHILD_H
#define CHILD_H

#include "utils.h"

class Child
{

public:
	struct xyz
	{
		int numPoints;
		Point ref;
		Point points[];
		Point closest;
	};

private:

};
#endif