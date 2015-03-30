#include "utils.h"
#include "Child.h"

#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
#include <limits>

using namespace std;

double utils::calculateDistance(Point a, Point b)
{
	int result = 0;

	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


int main(int argc, char * argv[])
{

	int segment_id  = atoi(argv[1]);//gets segment id
	package * pBuff = (package *) shmat(segment_id, NULL, 0);//casts segment id as char*, so process finds shared memory

	double distance = numeric_limits<double>::max();
	Point smallest;

	for(int i = 0; i < 100; i++)
	{
		double test = utils::calculateDistance(pBuff->points[i], pBuff->ref);

		if(test < distance)
		{
			distance = test;
			smallest = pBuff->points[i];
		}
	}

	//write 'smallest'(closest point) to memory
	pBuff->closest = smallest;

	



	return 0;
}

