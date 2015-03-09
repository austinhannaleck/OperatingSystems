#include "utils.h"
#include "Child.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
#include <limits>

using namespace std;


int main(int argc, char * argv[])
{

	int segment_id  = atoi(argv[1]);//gets segment id
	package * pBuff = (package *) shmat(segment_id, NULL, 0);//casts segment id as char*, so process finds shared memory
	cout << "Child seg id is " << segment_id << endl;
	//cout << pBuff->ref.x;
	cout << "Child process id is " << pBuff->points[0].x << " " << pBuff->points[0].y << endl;

	//int distance = numeric_limits<int>::max();
	//Point smallest;

	for(int i = 0; i < 10; i++)
	{
		// int test = calculateDistance(pBuff->points[i], pBuff->ref);
		// if(test < distance)
		// {
		// 	distance = test;
		// 	smallest = pBuff->points[i];
		// }
	}

	//write 'smallest' to memory



	return 0;
}

