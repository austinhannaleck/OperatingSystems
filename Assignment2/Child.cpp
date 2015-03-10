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
	//cout << "Child seg id is " << segment_id << endl;
	//cout << "Reference point is " << pBuff->ref.x << " " << pBuff->ref.y << endl;
	//cout << "Child process id is " << pBuff->points[0].x << " " << pBuff->points[0].y << endl;

	double distance = numeric_limits<double>::max();
	Point smallest;

	for(int i = 0; i < 100; i++)
	{
		double test = utils::calculateDistance(pBuff->points[i], pBuff->ref);
		//cout << pBuff->points[i].x << " " << pBuff->points[i].y << endl;
		if(test < distance)
		{
			distance = test;
			smallest = pBuff->points[i];
		}
	}

	cout << "final distance is " << distance << endl;

	pBuff->closest = smallest;

	//write 'smallest' to memory



	return 0;
}

